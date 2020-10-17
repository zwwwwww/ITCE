/*
From:ITC
6
Pointer related defects
6.2
Wrong arguments passed to a function pointer
6.2.7
function : one double argument and function pointer : two double arguments
*/
unsigned int wrong_arguments_func_pointer_007_func_001 (double a)
{
	a++;
	return ((unsigned int)(a));
}

void wrong_arguments_func_pointer_007 ()
{
	unsigned int (*func)(double);
	unsigned int ret;
	func = wrong_arguments_func_pointer_007_func_001;
	ret = func(10.005); /*Tool should not detect this line as error*//*No ERROR:Wrong arguments passed to a function pointer*/
}
