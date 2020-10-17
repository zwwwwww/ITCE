/*
From:ITC
7
Resource management defects
7.5
Memory leakage
7.5.15
 Memory allocated and returned from one function and Memory used in another function
*/
       
char * memory_leak_0015_func_001 (int len)
{
	char *stringPtr = malloc(sizeof(char) * (len+1));
	return stringPtr;
}

void memory_leak_0015 ()
{
	char *str = "This is a string";
	char *str1 = memory_leak_0015_func_001(strlen(str)); /*Tool should detect this line as error*/ /*ERROR:Memory Leakage */
	if(str1!=NULL)
	{
	    strcpy(str1,str);
	}
}
