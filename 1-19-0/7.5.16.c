/*
From:ITC
7
Resource management defects
7.5
Memory leakage
7.5.16
 Memory allocated in a function and Memory used in another function
*/
        
# define INDEX 'a'
static unsigned char a =INDEX;
char * memory_leak_0016_gbl_ptr;
void memory_leak_0016_func_001 (int len)
{
	memory_leak_0016_gbl_ptr=NULL;
	if(a == INDEX)
		memory_leak_0016_gbl_ptr= malloc(sizeof(char) * (len+1)); /*Tool should not detect  this line as error*/ /*No ERROR:Memory Leakage */
}

void memory_leak_0016 ()
{
	char *str = "This is a string";
	memory_leak_0016_func_001(strlen(str));
	strcpy(memory_leak_0016_gbl_ptr,str);
	free(memory_leak_0016_gbl_ptr);
	memory_leak_0016_gbl_ptr = NULL;
}