/*
From:ITC
5
Numerical defects
5.6
Integer sign lost because of unsigned cast
5.6.19
"unsigned int->signed	int	Also known as double Alias"
*/
  
extern int sink;       
void sign_conv_019 ()
{
	int a = 0x7fffffff;
	int a1;
	int a2;
	unsigned int ret;
	a1 = a;
	a2 = a1;
	ret = a2;
        sink = ret;
}
