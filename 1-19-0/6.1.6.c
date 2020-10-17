/*
From:ITC
6
Pointer related defects
6.1
Bad cast of a function pointer
6.1.6
return type function float ** and function pointer: char ** 
*/
      
extern int sink;             
float ** func_pointer_006_doubleptr_gbl=NULL;
int func_pointer_006_func_001(int flag)
{
   int ret;
   if (flag ==0)
	   ret = 0;
   else
	   ret=1;
   return ret;
}

float **  func_pointer_006_func_002()
{
	int i,j;
	func_pointer_006_doubleptr_gbl=(float **) malloc(10*sizeof(float*));

	for(i=0;i<10;i++)
	{
		func_pointer_006_doubleptr_gbl[i]=(float *) malloc(10*sizeof(float));
	}
	for(i=0;i<10;i++)
	{
		for(j=0;j<10;j++)
		{
			func_pointer_006_doubleptr_gbl[i][j]=i;
		}
	}
	return func_pointer_006_doubleptr_gbl;
}

float **  func_pointer_006_func_003()
{
	int i,j;
	for(i=0;i<10;i++)
	{
		for(j=0;j<10;j++)
		{
			func_pointer_006_doubleptr_gbl[i][j]=i;
		}
	}
	return func_pointer_006_doubleptr_gbl;
}

float **  func_pointer_006_func_004()
{
	int i;
	for(i=0;i<10;i++)
	{
	    free (func_pointer_006_doubleptr_gbl[i]);
	    func_pointer_006_doubleptr_gbl[i] = NULL;
	}
    free(func_pointer_006_doubleptr_gbl);
    func_pointer_006_doubleptr_gbl = NULL;
	return func_pointer_006_doubleptr_gbl;
}

void func_pointer_006()
{
	int flag=0,i,j;
	if(func_pointer_006_func_001(flag)==0)
	{
		float **(*fptr)();
	    fptr = func_pointer_006_func_002; 
	    func_pointer_006_doubleptr_gbl = fptr();/*Tool should not detect this line as error*/ /*No ERROR:Bad function pointer casting*/
	    fptr = func_pointer_006_func_003;
	    func_pointer_006_doubleptr_gbl = fptr();
	    for(i=0;i<10;i++)
	    {
	    	for(j=0;j<10;j++)
		    {
	    		func_pointer_006_doubleptr_gbl[i][j] += 1;
		    }
	    }
	    fptr = func_pointer_006_func_004;
	    func_pointer_006_doubleptr_gbl = fptr();
	}
}
