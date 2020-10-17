/*
From:ITC
6
Pointer related defects
6.1
Bad cast of a function pointer
6.1.1
return type function void and function pointer: int 
*/
    
void func_pointer_001_func_001 ()
{
	int a ;
	a =10;
}

void func_pointer_001 ()
{
	int (*func)();
	int ret;
	func = (int (*)( ))func_pointer_001_func_001;
	ret = func();/*Tool should detect this line as error*/ /*ERROR:Bad function pointer casting*/
}