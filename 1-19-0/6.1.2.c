/*
From:ITC
6
Pointer related defects
6.1
Bad cast of a function pointer
6.1.2
return type function int and function pointer: void
*/
  
extern int sink;           
int func_pointer_002_func_001(char a)
{
	a++;
	return (a);
}

void func_pointer_002 ()
{
 	char buf[10] = "string";
	int (*fptr)(char);
	int a;
	fptr = func_pointer_002_func_001; 
	a =fptr(buf[0]);/*Tool should not detect this line as error*/ /*No ERROR:Bad function pointer casting*/
        sink = a;
}
