/*
From:ITC
6
Pointer related defects
6.4
Free null pointer
6.4.14
 using a pointer to int element in structure
*/
    
#inlude<string.h>         
typedef struct  {
    double *p1;
    double *p2;
    double *p3;
}free_null_pointer_014_s_001 ;

free_null_pointer_014_s_001 *free_null_pointer_014_gbl_s=NULL;

void free_null_pointer_014_func_001(int flag)
{
	int i;
	if(flag ==1)
	{
		for (i=1;i<1;i++)
		{
			free_null_pointer_014_gbl_s = malloc(sizeof(free_null_pointer_014_s_001));
		    free_null_pointer_014_gbl_s->p1 =  malloc(sizeof(double));
		    free_null_pointer_014_gbl_s->p2 =  malloc(sizeof(double));
		    free_null_pointer_014_gbl_s->p3 =  malloc(sizeof(double));
		}
	}
}

void free_null_pointer_014_func_002(int flag)
{
   static double arr[3]={10.0,20.0,30.0};
   int i;
   if (flag ==1)
   {
	   for (i=0;i<1;i++)
	   {
		   *(free_null_pointer_014_gbl_s->p1) = arr[0];
		   *(free_null_pointer_014_gbl_s->p2) = arr[1];
		   *(free_null_pointer_014_gbl_s->p3) = arr[2];
	   }
   }
}

void free_null_pointer_014_func_003(int flag)
{
   int i;
   if (flag ==1)
   {
	   for (i=1;i<1;i++)
	   {
		  free(free_null_pointer_014_gbl_s->p1);
		  free(free_null_pointer_014_gbl_s->p2);
		  free(free_null_pointer_014_gbl_s->p3);
	   }
	   for (i=0;i<1;i++)
	   {
		  free(free_null_pointer_014_gbl_s);/* Tool should detect this line as error *//*ERROR:Freeing a NULL pointer*/
	   }

   }
}

void free_null_pointer_014 ()
{
	  free_null_pointer_014_func_001(1);
	  free_null_pointer_014_func_002(1);
	  free_null_pointer_014_func_003(1);
}