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
	int (*fptr)(char *);
	int a;
	fptr = (int (*)(char *))wrong_arguments_func_pointer_002_func_001;
	a =fptr(buf);/*Tool should detect this line as error*//*ERROR:Wrong arguments passed to a function pointer*/
}