/*
From:ITC
6
Pointer related defects
6.2
Wrong arguments passed to a function pointer
6.2.4
function : char * and function pointer : float
*/
char wrong_arguments_func_pointer_004_func_001 (char *p)
{
	return (*p);
}

void wrong_arguments_func_pointer_004 ()
{
    char (*func)(char*);
	char buf[10] = ""string"";
	char ret;
	func = wrong_arguments_func_pointer_004_func_001;
	ret = func(buf); /*Tool should not detect this line as error*//*No ERROR:Wrong arguments passed to a function pointer*/
}
