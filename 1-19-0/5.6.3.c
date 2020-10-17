/*
From:ITC
5
Numerical defects
5.6
Integer sign lost because of unsigned cast
5.6.3
signed int->unsigned int
*/
         
extern int sink;            
void sign_conv_003 ()
{
	unsigned int a = 0x7fffffff;
	int ret;
	ret = a; /*Tool should not detect this line as error*/ /*NO ERROR : Integer sign lost because of unsigned cast */
        sink = ret;
}
