/*
From:ITC
6
Pointer related defects
6.2
Wrong arguments passed to a function pointer
6.2.2
function : int and function pointer : char *
*/
int wrong_arguments_func_pointer_002_func_001(int a)
{
    int i=20;
	return (i);
}

void wrong_arguments_func_pointer_002 ()
{
	char buf[10] = "string";
	int (*fptr)(int);
	int a;
	fptr = wrong_arguments_func_pointer_002_func_001;
	a =fptr(buf[0]); /*Tool should not detect this line as error*//*No ERROR:Wrong arguments passed to a function pointer*/
}
