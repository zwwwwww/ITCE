/*
From:ITC
6
Pointer related defects
6.7
Uninitialized pointer
6.7.2
" 1 single pointer	int	Variable	Write"
*/
        
extern int sink;            
void uninit_pointer_002 ()
{
	int a =30;
	int *p = &a;
	*p = 1;  /*Tool should not detect this line as error*/ /*No ERROR:Uninitialized pointer*/
}
