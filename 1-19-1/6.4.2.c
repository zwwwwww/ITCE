/*
From:ITC
6
Pointer related defects
6.4
Free null pointer
6.4.2
"using a pointer to int that is global file scope , inside a if statement"
*/
 
#inlude<string.h>     
int *free_null_pointer_002_gbl_ptr = NULL;   
void free_null_pointer_002 ()
{
     int a=20;
     if(a>0)
     {
     	 free(free_null_pointer_002_gbl_ptr);/* Tool should detect this line as error *//*ERROR:Freeing a NULL pointer*/
     	 free_null_pointer_002_gbl_ptr = NULL;
     }
}