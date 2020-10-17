/*
From:ITC
6
Pointer related defects
6.1
Bad cast of a function pointer
6.1.1
return type function void and function pointer: int 
*/
         
extern int sink;              
void func_pointer_001_func_001 ()
{
	int a ;
	a =10;
        sink = a;
}

void func_pointer_001 ()
{
	void (*func)();
	func = func_pointer_001_func_001; 
	func();/*Tool should not detect this line as error*/ /*No ERROR:Bad function pointer casting*/
}
