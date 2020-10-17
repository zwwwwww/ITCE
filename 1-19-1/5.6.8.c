/*
From:ITC
5
Numerical defects
5.6
Integer sign lost because of unsigned cast
5.6.8
unsigned long->signed long
*/

extern int sink;    
void sign_conv_008 ()
{
	long a = -1;
	unsigned long ret;
	ret = a;/*Tool should detect this line as error*/ /*Integer sign lost because of unsigned cast */
        sink = ret;
}
