/*
From:ITC
6
Pointer related defects
6.7
Uninitialized pointer
6.7.8
"structure	int	Function arguments	Loading"
*/
              
typedef struct {
	int a;
	int b;
	int uninit;
} uninit_pointer_008_s_001;

void uninit_pointer_008_func_001 (uninit_pointer_008_s_001 *p)
{
	int ret = 10;
	p->uninit = ret;
}
void uninit_pointer_008 ()
{
	uninit_pointer_008_s_001 s;
	s.a = 1;
	s.b = 1;
	s.uninit = 1;
	uninit_pointer_008_func_001(&s); /*Tool should not detect this line as error*/ /*No ERROR:Uninitialized pointer*/
}
