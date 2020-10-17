/*
From:ITC
6
Pointer related defects
6.7
Uninitialized pointer
6.7.3
"using a double pointer	int	Variable"
*/
  
void uninit_pointer_003 ()
{
	int **pp;
	int *p;
	int a = 0;
	int ret;
	pp = &p;
	ret = **pp; /*Tool should detect this line as error*/ /*ERROR:Uninitialized pointer*/
}
