/*
From:ITC
6
Pointer related defects
6.1
Bad cast of a function pointer
6.1.5
return type function long ** and function pointer: void 
*/
     
int func_pointer_005_func_001(int flag)
{
   int ret =0;
   if (flag ==0)
	   ret = 0;
   else
	   ret=1;
   return ret;
}

long **  func_pointer_005_func_002()
{
	int i,j;
	long ** doubleptr;
	doubleptr=(long**) malloc(10*sizeof(long*));

	for(i=0;i<10;i++)
	{
		doubleptr[i]=(long*) malloc(10*sizeof(long));
	}
	for(i=0;i<10;i++)
	{
		for(j=0;j<10;j++)
		{
			doubleptr[i][j]=i;
		}
	}
	return doubleptr;
}

void func_pointer_005()
{
	int flag=0,i,j;
	long ** doubleptr=NULL;

	if(func_pointer_005_func_001(flag)==0)
	{
		void (*fptr)(void);
	    fptr = (void (*)(void ))func_pointer_005_func_002;
	    fptr();/*Tool should detect this line as error*/ /*ERROR:Bad function pointer casting*/
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
