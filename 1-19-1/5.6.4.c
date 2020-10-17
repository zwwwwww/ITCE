/*
From:ITC
5
Numerical defects
5.6
Integer sign lost because of unsigned cast
5.6.4
signed long->unsigned long
*/
   
extern int sink;      
void sign_conv_004 ()
{
	unsigned long a = 0xffffffff;
	long ret;
	ret = a;/*Tool should detect this line as error*/ /*Integer sign lost because of unsigned cast */
        sink = ret;
}
