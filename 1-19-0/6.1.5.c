/*
From:ITC
6
Pointer related defects
6.1
Bad cast of a function pointer
6.1.5
return type function long ** and function pointer: void 
*/
     
extern int sink;            
int func_pointer_005_func_001(int flag)
{
   int ret;
   if (flag ==0)
	   ret = 0;
   else
	   ret=1;
   return ret;
}

long **  func_pointer_005_func_002()
{
	int i,j;
	func_pointer_005_doubleptr_gbl=(long**) malloc(10*sizeof(long*));

	for(i=0;i<10;i++)
	{
		func_pointer_005_doubleptr_gbl[i]=(long*) malloc(10*sizeof(long));
	}
	for(i=0;i<10;i++)
	{
		for(j=0;j<10;j++)
		{
			func_pointer_005_doubleptr_gbl[i][j]=i;
		}
	}
	return func_pointer_005_doubleptr_gbl;
}

void func_pointer_005()
{
 	int flag=0,i,j;
	long ** doubleptr=NULL;

	if(func_pointer_005_func_001(flag)==0)
	{
		long **(*fptr)(); 
	    fptr = func_pointer_005_func_002;
	    doubleptr = fptr();/*Tool should not detect this line as error*/ /*No ERROR:Bad function pointer casting*/
	    for(i=0;i<10;i++)
	    {
	    	for(j=0;j<10;j++)
		    {
	    		doubleptr[i][j] += 1;
		    }
		    free (doubleptr[i]);
		    doubleptr[i] = NULL;
	    }
        free(doubleptr);
        doubleptr = NULL;
	}
}
