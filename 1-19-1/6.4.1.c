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
	char* buf= NULL;
	free(buf);/* Tool should detect this line as error */ /*ERROR:Freeing a NULL pointer*/
	buf = NULL;
}