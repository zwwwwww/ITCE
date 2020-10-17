/*
From:ITC
6
Pointer related defects
6.7
Uninitialized pointer
6.7.4
"1 single pointer	int	Function arguments	Loading"
*/
                              
void uninit_pointer_004_func_001 (int *p)
{
	int ret;
	ret = 0;
}
void uninit_pointer_004 ()
{
	int a = 0;
	int *p ;
	uninit_pointer_004_func_001(p);/*Tool should detect this line as error*/ /*ERROR:Uninitialized pointer*/
}