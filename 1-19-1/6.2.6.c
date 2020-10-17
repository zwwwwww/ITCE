/*
From:ITC
6
Pointer related defects
6.2
Wrong arguments passed to a function pointer
6.2.6
function : two int arguments and function pointer : one int argument
*/
      
int wrong_arguments_func_pointer_006_func_001 (int a, int b)
{
	return a + b;
}

void wrong_arguments_func_pointer_006 ()
{
	int (*func)(int);
	int ret;
	func = (int (*)(int))wrong_arguments_func_pointer_006_func_001;
	ret = func(5);/*Tool should detect this line as error*//*ERROR:Wrong arguments passed to a function pointer*/

}
