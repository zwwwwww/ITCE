/*
From:ITC
6
Pointer related defects
6.7
Uninitialized pointer
6.7.15
int variable initialized with function return value using enumeration
*/
                             
typedef enum
            {ZERO,
	         ONE,
	         TWO } values;

void uninit_pointer_015_func_001 (int *ptr )
{
	values val = ONE;
	*ptr = val;
}

void uninit_pointer_015 ()
{
    int  a=0, *ptr = &a;
    uninit_pointer_015_func_001(ptr); /*Tool should not detect this line as error*/ /*No ERROR:Uninitialized pointer*/
}
