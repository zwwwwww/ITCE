/*
From:ITC
6
Pointer related defects
6.1
Bad cast of a function pointer
6.1.6
return type function float ** and function pointer: char ** 
*/
         
float ** doubleptr=NULL;
int func_pointer_006_func_001(int flag)
{
   int ret =0;
   if (flag ==0)
	   ret = 0;
   else
	   ret=1;
   return ret;
}

float **  func_pointer_006_func_002()
{
	int i,j;
	doubleptr=(float **) malloc(10*sizeof(float*));

	for(i=0;i<10;i++)
	{
		doubleptr[i]=(float *) malloc(10*sizeof(float));
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

float **  func_pointer_006_func_003()
{
	int i,j;
	for(i=0;i<10;i++)
	{
		for(j=0;j<10;j++)
		{
			doubleptr[i][j]=i;
		}
	}
	return doubleptr;
}

float **  func_pointer_006_func_004()
{
	int i;
	for(i=0;i<10;i++)
	{
	    free (doubleptr[i]);
	    doubleptr[i] = NULL;
	}
    free(doubleptr);
    doubleptr = NULL;
	return doubleptr;
}

void func_pointer_006()
{
 	int flag=0,i,j;
	if(func_pointer_006_func_001(flag)==0)
	{
		char **(*fptr)();
		char **doubleptr;
	    fptr = (char ** (*)(void))func_pointer_006_func_002;
	    doubleptr = fptr();/*Tool should detect this line as error*/ /*ERROR:Bad function pointer casting*/
	    doubleptr = (char **)func_pointer_006_func_003();
	    for(i=0;i<10;i++)
	    {
	    	for(j=0;j<10;j++)
		    {
	    		doubleptr[i][j] += 1;
		    }
	    }
	    doubleptr = (char **)func_pointer_006_func_004();
	}
}
