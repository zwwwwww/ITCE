/*
From:ITC
6
Pointer related defects
6.1
Bad cast of a function pointer
6.1.10
single alias
*/
   
extern int sink;         
void func_pointer_010_func_001 ()
{
	int a;
	a= 10;
        sink = a;
}

void func_pointer_010 ()
{
	void (*func)();
	void (*func1)();
	func = func_pointer_010_func_001; /*Tool should not detect this line as error*/ /*No ERROR:Bad function pointer casting*/
	func1 = func;
	func1();
}
