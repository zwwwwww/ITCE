/*
From:ITC
5
Numerical defects
5.6
Integer sign lost because of unsigned cast
5.6.9
signed bitfiled->unsigned bitfiled
*/
typedef struct {

	unsigned int a : 5;
	signed int ret : 5;
} sign_conv_009_s_001;

void sign_conv_009 ()
{
	sign_conv_009_s_001 s;
	s.a = 0x1f;
	s.ret = s.a;/*Tool should detect this line as error*/ /*Integer sign lost because of unsigned cast */
}
