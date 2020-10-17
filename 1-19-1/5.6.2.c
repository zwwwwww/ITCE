/*
From:ITC
5
Numerical defects
5.6
Integer sign lost because of unsigned cast
5.6.2
signed short->unsigned short
*/
   
extern int sink;      
void sign_conv_002 ()
{
	unsigned short a = 0xffff;
	short ret;
	ret = a;/*Tool should detect this line as error*/ /*Integer sign lost because of unsigned cast */
        sink = ret;
}
