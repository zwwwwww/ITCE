/*
From:ITC
6
Pointer related defects
6.1
Bad cast of a function pointer
6.1.14
int and function pointer: float
*/
         
extern int sink;               
int func_pointer_014_func_001 (void)
{
	int a;
	a= 10;
	return a;
}

int func_pointer_014_func_002 (int flag)
{
	int ret = 0;
	if (flag == 1)
	{
		goto my_label;
	}

	return ret;

my_label:
    if (flag == 1)
	{
        func_gbl = func_pointer_014_func_001; 

        goto my_label2;
 	ret ++;
	}

my_label2:
    if (flag == 1)
 	{
          flag = func_gbl();/*Tool should not detect this line as error*/ /*No ERROR:Bad function pointer casting*/
 	}
	return ret;
}

void func_pointer_014 ()
{
    int flag;
    int (*fptr)(int);
    fptr =func_pointer_014_func_002;
    flag = fptr(1);
    sink = flag;
}
