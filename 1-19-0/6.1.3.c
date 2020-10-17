/*
From:ITC
6
Pointer related defects
6.1
Bad cast of a function pointer
6.1.3
return type function long and function pointer: float
*/
   
extern int sink;           
long func_pointer_003_func_001 (long a, int b)
{
	return (a + (long)b);
}

void func_pointer_003 ()
{
 	long ret;
	if(1)
	{
		long (*func)(long , int);
		func = func_pointer_003_func_001; 
		ret = func(1, 2);/*Tool should not detect this line as error*/ /*No ERROR:Bad function pointer casting*/
	}
        sink = ret;
}
