/*
From:ITC
5
Numerical defects
5.6
Integer sign lost because of unsigned cast
5.6.10
unsigned bitfiled->signed bitfiled
*/
                
extern int sink;                  
typedef struct {
	signed int a : 5;
	unsigned int ret : 5;
} sign_conv_010_s_001;

void sign_conv_010 ()
{
	sign_conv_010_s_001 s;
	s.a = 0x0f;
	s.ret = s.a; /*Tool should not detect this line as error*/ /*NO ERROR : Integer sign lost because of unsigned cast */
}
