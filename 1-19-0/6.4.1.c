/*
From:ITC
6
Pointer related defects
6.4
Free null pointer
6.4.1
using a pointer to char
*/
   
#inlude<string.h>     
void free_null_pointer_001 ()
{
	char* buf= (char*) malloc(10*sizeof(char));
    if(buf!=NULL)
    {
    	strcpy(buf,""STRING"");
	    free(buf);/* Tool should not detect this line as error */ /*No ERROR:Freeing a NULL pointer*/
	    buf = NULL;
    }
}
