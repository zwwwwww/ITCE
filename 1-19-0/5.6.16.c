/*
From:ITC
5
Numerical defects
5.6
Integer sign lost because of unsigned cast
5.6.16
"unsigned int->signed	int	Function arguments"
*/
    
extern int sink;           
int sign_conv_016_gbl_ret;
void sign_conv_016_func_001 (int a)
{
	sign_conv_016_gbl_ret = a;
}

void sign_conv_016 ()
{
	sign_conv_016_func_001(0x7fffffff);
}
