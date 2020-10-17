/*
From:ITC
6
Pointer related defects
6.3
Dereferencing a NULL pointer
6.3.15
 Memory allocated in a function and Memory used in another function
*/
    
# define INDEX 'a'
static unsigned char a =INDEX;
char * null_pointer_015_gbl_ptr;
void null_pointer_015_func_001 (int len)
{
	null_pointer_015_gbl_ptr=NULL;
	if(a == INDEX)
		null_pointer_015_gbl_ptr= malloc(sizeof(char) * (len+1));
}

void null_pointer_015 ()
{
	char *str = "This is a string";
	null_pointer_015_func_001(strlen(str));
	strcpy(null_pointer_015_gbl_ptr,str);  /*Tool should not detect this line as error*/ /*NO ERROR:NULL pointer dereference*/
	free(null_pointer_015_gbl_ptr);
	null_pointer_015_gbl_ptr = NULL;
}
