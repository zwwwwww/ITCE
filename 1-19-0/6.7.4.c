/*
From:ITC
6
Pointer related defects
6.7
Uninitialized pointer
6.7.4
"1 single pointer	int	Function arguments	Loading"
*/
   
extern int sink;       
void uninit_pointer_004_func_001 (int *p)
{
	int ret=10;
	*p = ret;
        sink = ret;
}
void uninit_pointer_004 ()
{
	int a = 10;
	int *p = &a;
	uninit_pointer_004_func_001(p); /*Tool should not detect this line as error*/ /*No ERROR:Uninitialized pointer*/
}
