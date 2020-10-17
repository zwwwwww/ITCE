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
	unsigned int (*func)(double, double);
	unsigned int ret;
	func = (unsigned int (*)(double,double))wrong_arguments_func_pointer_007_func_001;
	ret = func(1.005, 2.005);/*Tool should detect this line as error*//*ERROR:Wrong arguments passed to a function pointer*/
}