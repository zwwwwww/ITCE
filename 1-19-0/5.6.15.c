/*
From:ITC
5
Numerical defects
5.6
Integer sign lost because of unsigned cast
5.6.15
"unsigned int->signed	int	The return value of the function"
*/
             
extern int sink;                 
unsigned int sign_conv_015_gbl_ret;
int sign_conv_015_func_001 ()
{
	return 0x7fffffff;
}

void sign_conv_015 ()
{
	sign_conv_015_gbl_ret = sign_conv_015_func_001();/*Tool should not detect this line as error*/ /*NO Error Integer sign lost because of unsigned cast */
}
