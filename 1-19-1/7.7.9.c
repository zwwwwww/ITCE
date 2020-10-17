/*
From:ITC
7
Resource management defects
7.7
Uninitialized memory access
7.7.9
"using array of double pointer to long -  Memory is  allocated based on return value of function ,initialized and accessed"
*/
   
long ** uninit_memory_access_009_doubleptr_gbl;         
int uninit_memory_access_009_func_001(int flag)
{
   int ret;
   if (flag ==0)
	   ret = 0;
   else
	   ret=1;
   return ret;
}

void uninit_memory_access_009_func_002()
{
	int i,j;
	uninit_memory_access_009_doubleptr_gbl=(long**) malloc(10*sizeof(long*));

	for(i=0;i<10;i++)
	{
		uninit_memory_access_009_doubleptr_gbl[i]=(long*) malloc(10*sizeof(long));
	}
	for(i=0;i<10;i++)
	{
		for(j=0;j<10;j++)
		{
			;/*uninit_memory_access_009_doubleptr_gbl[i][j]=i;*/
		}
	}
}

void uninit_memory_access_009()
{
	int flag=0,i,j;

	if(uninit_memory_access_009_func_001(flag)==0)
	{
		uninit_memory_access_009_func_002();
	}
    if(uninit_memory_access_009_func_001(flag)==0)
	{
		for(i=0;i<10;i++)
		{
			for(j=0;j<10;j++)
			{
				uninit_memory_access_009_doubleptr_gbl[i][j] += 1;/*Tool should detect this line as error*/ /*ERROR:Uninitialized Memory Access*/
			}
			free (uninit_memory_access_009_doubleptr_gbl[i]);
			uninit_memory_access_009_doubleptr_gbl[i] = NULL;
	   }
	    free(uninit_memory_access_009_doubleptr_gbl);
	    uninit_memory_access_009_doubleptr_gbl = NULL;
	}
}