/*
From:ITC
6
Pointer related defects
6.7
Uninitialized pointer
6.7.2
" 1 single pointer	int	Variable	Write"
*/
void uninit_pointer_002 ()
{
	int a;
	int *p ;
	*p = 1; /*Tool should detect this line as error*/ /*ERROR:Uninitialized pointer*/
}