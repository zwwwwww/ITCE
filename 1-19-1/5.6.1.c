/*
From:ITC
5
Numerical defects
5.6
Integer sign lost because of unsigned cast
5.6.1
char signed -> unsigned char
*/
     
extern int sink;     
void sign_conv_001 ()
{
	unsigned char a = 0xff;
	char ret;
	ret = a; /*Tool should detect this line as error*/ /*Integer sign lost because of unsigned cast */
        sink = ret;
}
