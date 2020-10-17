/*
From:ITC
5
Numerical defects
5.6
Integer sign lost because of unsigned cast
5.6.5
unsigned char->signed char
*/
       
extern int sink;            
void sign_conv_005 ()
{
	char a = 0x7f;
	unsigned char ret;
	ret = a; /*Tool should not detect this line as error*/ /*NO ERROR : Integer sign lost because of unsigned cast */
        sink = ret;
}
