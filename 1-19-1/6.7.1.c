/*
From:ITC
6
Pointer related defects
6.7
Uninitialized pointer
6.7.1
"using a single pointer int	Variable - Loading"
*/
                 
void uninit_pointer_001 ()
{
	int a = 5;
	int *p ;  
	int ret;
	ret = *p; /*Tool should detect this line as error*/ /*ERROR:Uninitialized pointer*/
}