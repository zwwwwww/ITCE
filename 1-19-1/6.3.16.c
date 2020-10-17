/*
From:ITC
6
Pointer related defects
6.3
Dereferencing a NULL pointer
6.3.16
"When using a double pointer to long , memory allocated in another function inside goto label and if condition"
*/

long ** null_pointer_016_gbl_doubleptr;
int null_pointer_016_func_001(int flag)
{
   int ret ;
   if (flag ==0)
	   ret = 0;
   else
	   ret=1;
   return ret;
}
void null_pointer_016_func_002()
{
	int i,j;
	null_pointer_016_gbl_doubleptr=(long**) malloc(10*sizeof(long*));

	for(i=0;i<10;i++)
	{
		null_pointer_016_gbl_doubleptr[i]=(long*) malloc(10*sizeof(long));
	}
	for(i=0;i<10;i++)
	{
		for(j=0;j<10;j++)
		{
			null_pointer_016_gbl_doubleptr[i][j]=i;
		}
	}
}

#define ZERO 0
void null_pointer_016()
{
	int flag=0,i,j;
	null_pointer_016_gbl_doubleptr=NULL;
goto label;

    if(null_pointer_016_func_001(flag)==ZERO)
	{
		for(i=0;i<10;i++)
		{
			for(j=0;j<10;j++)
			{
				null_pointer_016_gbl_doubleptr[i][j] += 1;/*Tool should detect this line as error*/ /*ERROR:NULL pointer dereference*/
			}
			free (null_pointer_016_gbl_doubleptr[i]);
			null_pointer_016_gbl_doubleptr[i] = NULL;
	   }
	    free(null_pointer_016_gbl_doubleptr);
	    null_pointer_016_gbl_doubleptr = NULL;
	}

label:
    	if(null_pointer_016_func_001(flag)!=ZERO)
    	{
    		null_pointer_016_func_002();
    	}
}
