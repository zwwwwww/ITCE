/*
From:ITC
6
Pointer related defects
6.1
Bad cast of a function pointer
6.1.10
single alias
*/
      
void func_pointer_010_func_001 ()
{
	int a;
	a= 10;
}

void func_pointer_010 ()
{
	int (*func)();
	int (*func1)();
	int ret;
	func = (int (*)(void))func_pointer_004_func_001;
	func1 = func;
	ret = func1();/*Tool should detect this line as error*/ /*ERROR:Bad function pointer casting*/
}