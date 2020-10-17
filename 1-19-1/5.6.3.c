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
	unsigned int a = 0xffffffff;
	int ret;
	ret = a;/*Tool should detect this line as error*/ /*Integer sign lost because of unsigned cast */
        sink = ret;
}
