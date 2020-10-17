/*
From:ITC
5
Numerical defects
5.6
Integer sign lost because of unsigned cast
5.6.17
"unsigned int->signed	int	An array of element values"
*/
     
extern int sink;          
int sign_conv_017_gbl_buf[5] = {1, 2, 3, -4, 5};
int sign_conv_017_gbl_ret;
void sign_conv_017 ()
{
	sign_conv_017_gbl_ret = sign_conv_017_gbl_buf[3];
}
