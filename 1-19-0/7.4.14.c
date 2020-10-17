/*
From:ITC
7
Resource management defects
7.4
Memory allocation failure
7.4.14
"sing a pointer to an array of integer in if condition and
* memory allocated and return from another function based on value of array"
*/
       
#define MAX_VAL 10         
const int arr_value[2] = {1,MAX_VAL};
int (*memory_allocation_failure_014_func_001())[4]
{
	int (*p)[4];
	int arr[4][4] = {{1,2,3,4},
			         {11,22,33,44},
			         {33,44,55,66},
			         {55,66,77,88}};
	int i,j;
	p= (int (*)[]) malloc (arr_value[0] * sizeof arr); /*Tool should not detect this line as error*/ /*No ERROR:Memory allocation failure */
	if(p!=NULL)
	{
	memcpy(p, arr, sizeof(arr));
	for (i = 0;i< 4; i++)
	{
		for ( j=0 ;j<4; j++)
		{
			*(p[i]+j) += *(p[i]+j);
		}
	}
	}
	return p;
}

void memory_allocation_failure_014 ()
{
	int (*ptr1)[4];
	char  **dptr,a = 0;
	double *ptr,b;
	int i,j;
	static int staticflag=10;
    if (staticflag == 10)
    {
    	  	ptr= (double*) malloc(10*sizeof(double));
    }
    else
    {
    	  	dptr=(char**) malloc(10*sizeof(char*));
    	  	if(1)
    	  	{
            	for(i=0;i<10;i++)
        	    {
            		dptr[i]=(char*) malloc(10*sizeof(char));
        	    }
            	ptr1 = memory_allocation_failure_014_func_001();
    	  	}
    }

    if  (staticflag == 10)
    {
    	(*(ptr+1) = 10.5);
    }
    else
    {
    	   strcpy( dptr[1],"STRING TEST" );
    	   if(1)
    	   {
        	   for (i = 0;i< 4; i++)
               	{
               		for ( j=0 ;j<4; j++)
               		{
               			*(ptr1[i]+j) += *(ptr1[i]+j);
               		}
               	}
    	   }


    }

    if(staticflag == 10)
    {
    	b = *(ptr+1);
    }
    else
    {
	  	if(1)
	  	{
	  		a = *(ptr1[1]+1);
	  	}
    }

    if(staticflag == 10)
    {
    	free(ptr);
    	ptr = NULL;
    }
    else
    {
    	for(i=0;i<10;i++)
    		free(dptr[i]);
    	free(dptr);
    	if(1)
    	{
    		free(ptr1);
    	}
    }
    printf("%d %lf",a,b);
}
