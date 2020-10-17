/*
From:ITC
6
Pointer related defects
6.2
Wrong arguments passed to a function pointer
6.2.3
function : int * and function pointer : int
*/
     
int wrong_arguments_func_pointer_003_func_001 (int *p)
{
	return (*p);
}

void wrong_arguments_func_pointer_003 ()
{
	int (*func)(int);
	int a = 1;
	int ret;
	func = (int (*)(int))wrong_arguments_func_pointer_003_func_001;
	ret = func(a);/*Tool should detect this line as error*//*ERROR:Wrong arguments passed to a function pointer*/
}