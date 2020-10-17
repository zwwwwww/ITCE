/*
From:ITC
5
Numerical defects
5.6
Integer sign lost because of unsigned cast
5.6.13
"unsigned int->signed	int	Linear equation"
*/
     
extern int sink;         
void sign_conv_013 ()
{
	int a = -1;
	unsigned int ret;
	ret = (5 * a) + 6; /*Tool should not detect this line as error*/ /*NO ERROR : Integer sign lost because of unsigned cast */
        sink = ret;
}
