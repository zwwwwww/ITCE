/*
From:ITC
6
Pointer related defects
6.4
Free null pointer
6.4.7
"using a double pointer to long , memory allocated in another function inside goto label and if condition"
*/
    
     
long ** free_null_pointer_007_gbl_doubleptr;
int free_null_pointer_007_func_001(int flag)
{
   int ret ;
   if (flag ==0)
	   ret = 0;
   else
	   ret=1;
   return ret;
}
void free_null_pointer_007_func_002()
{
	int i,j;
	free_null_pointer_007_gbl_doubleptr=(long**) malloc(10*sizeof(long*));

	for(i=0;i<10;i++)
	{
		free_null_pointer_007_gbl_doubleptr[i]=(long*) malloc(10*sizeof(long));
	}
	for(i=0;i<10;i++)
	{
		for(j=0;j<10;j++)
		{
			free_null_pointer_007_gbl_doubleptr[i][j]=i;
		}
	}
}

#define ZERO 0
void free_null_pointer_007()
{
	int flag=0,i,j;
	free_null_pointer_007_gbl_doubleptr=NULL;
goto label;

    if(free_null_pointer_007_func_001(flag)==ZERO)
	{
		for(i=0;i<10;i++)
		{
			for(j=0;j<10;j++)
			{
				free_null_pointer_007_gbl_doubleptr[i][j] += 1;
			}
			free (free_null_pointer_007_gbl_doubleptr[i]);
			free_null_pointer_007_gbl_doubleptr[i] = NULL;
	   }
	    free(free_null_pointer_007_gbl_doubleptr);/* Tool should not detect this line as error */ /*No ERROR:Freeing a NULL pointer*/
	    free_null_pointer_007_gbl_doubleptr = NULL;
	}

label:
    	if(free_null_pointer_007_func_001(flag)==ZERO)
    	{
    		free_null_pointer_007_func_002();
    	}
}
