/*
From:ITC
7
Resource management defects
7.5
Memory leakage
7.5.3
 Memory allocated in a function and Memory used in another function
*/
void memory_leak_003_func_001 (int len,char **stringPtr)
{
	char * p = malloc(sizeof(char) * (len+1));
	*stringPtr = p;
}

void memory_leak_003 ()
{
	char *str = "This is a string";
	char *str1;
	memory_leak_003_func_001(strlen(str),&str1); /*Tool should not detect  this line as error*/ /*No ERROR:Memory Leakage */
	strcpy(str1,str);
	free(str1);
}
