/*
From:ITC
6
Pointer related defects
6.4
Free null pointer
6.4.5
Memory allocated in a function and Memory used in another function
*/

#inlude<string.h>        
# define INDEX 'a'
static unsigned char a =INDEX;
char * free_null_pointer_005_gbl_ptr;
void free_null_pointer_005_func_001 (int len)
{
	free_null_pointer_005_gbl_ptr=NULL;
	if(a != INDEX)
		free_null_pointer_005_gbl_ptr= malloc(sizeof(char) * (len+1));
}

void free_null_pointer_005 ()
{
	char *str = ""This is a string"";
	free_null_pointer_005_func_001(strlen(str));
	strcpy(free_null_pointer_005_gbl_ptr,str);
	free(free_null_pointer_005_gbl_ptr); /* Tool should detect this line as error *//*ERROR:Freeing a NULL pointer*/
	free_null_pointer_005_gbl_ptr = NULL;
}