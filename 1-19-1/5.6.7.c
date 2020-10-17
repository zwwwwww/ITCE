/*
From:ITC
5
Numerical defects
5.6
Integer sign lost because of unsigned cast
5.6.7
unsigned int->signed int
*/

extern int sink;     
void sign_conv_007 ()
{
	int a = -1;
	unsigned int ret;
	ret = a;/*Tool should detect this line as error*/ /*Integer sign lost because of unsigned cast */
        sink = ret;
}
