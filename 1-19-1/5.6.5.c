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
	char a = -1;
	unsigned char ret;
	ret = a;/*Tool should detect this line as error*/ /*Integer sign lost because of unsigned cast */
        sink = ret;
}
