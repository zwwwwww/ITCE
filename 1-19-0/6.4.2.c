/*
From:ITC
6
Pointer related defects
6.4
Free null pointer
6.4.2
"using a pointer to int that is global file scope , inside a if statement"
*/
         
        
int *free_null_pointer_002_gbl_ptr = NULL;    
void free_null_pointer_002 ()
{
     int a=20;
     if(a>0)
     {
         free_null_pointer_002_gbl_ptr = (int*)calloc(10,sizeof(int));
         if(free_null_pointer_002_gbl_ptr!= NULL)
         {
        	 *free_null_pointer_002_gbl_ptr = a;
     	     free(free_null_pointer_002_gbl_ptr);/* Tool should not detect this line as error */ /*No ERROR:Freeing a NULL pointer*/
     	     free_null_pointer_002_gbl_ptr = NULL;
         }
     }
}
