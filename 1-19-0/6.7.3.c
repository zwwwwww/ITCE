/*
From:ITC
6
Pointer related defects
6.7
Uninitialized pointer
6.7.3
"using a double pointer	int	Variable"
*/
    
extern int sink;        
void uninit_pointer_003 ()
{
	int **pp = NULL;
	int *p = NULL;
	int a = 20;
	int ret;
	p = &a;
	pp = &p;
	ret = **pp; /*Tool should not detect this line as error*/ /*No ERROR:Uninitialized pointer*/
        sink = ret;
}
