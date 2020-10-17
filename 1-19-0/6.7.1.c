/*
From:ITC
6
Pointer related defects
6.7
Uninitialized pointer
6.7.1
"using a single pointer int	Variable - Loading"
*/
      
extern int sink;          
void uninit_pointer_001 ()
{
	int a = 5;
	int *p = &a;
	int ret;
	ret = *p; /*Tool should not detect this line as error*/ /*No ERROR:Uninitialized pointer*/
        sink = ret;
}
