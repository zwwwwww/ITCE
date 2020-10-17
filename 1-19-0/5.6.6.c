/*
From:ITC
5
Numerical defects
5.6
Integer sign lost because of unsigned cast
5.6.6
unsigned short->signed short
*/
                             
extern int sink;                                
void sign_conv_006 ()
{
	short a = 0x7fff;
	unsigned short ret;
	ret = a; /*Tool should not detect this line as error*/ /*NO ERROR : Integer sign lost because of unsigned cast */
        sink = ret;
}
