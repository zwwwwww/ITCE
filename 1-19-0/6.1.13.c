/*
From:ITC
6
Pointer related defects
6.1
Bad cast of a function pointer
6.1.13
pointer to array of Int * and typedef and function pointer: float *
*/
     
extern int sink;          
int func_pointer_013_func_001 ()
{
	int a;
	a= 10;
	return a;
}

int func_pointer_013_func_002 (int flag)
{
	int ret = 0;
	int arr[]={3,8,9,10,4};
	int *ptr;
	if (flag == 1)
	{
		goto my_label;
	}
	return ret;
my_label:
    if (flag == 1)
	{
        int (*func_gbl)(void );
        func_gbl = func_pointer_013_func_001; 
        flag = func_gbl();/*Tool should not detect this line as error*/ /*No ERROR:Bad function pointer casting*/
	}
	ptr = &arr[0];
	*(ptr+1) = 7;
	ret ++;
	return ret;
}

void func_pointer_013 ()
{
    int flag;
    int (*func_gbl)(int );
    func_gbl = func_pointer_013_func_002;
    flag = func_gbl(1);
    sink = flag;
}
