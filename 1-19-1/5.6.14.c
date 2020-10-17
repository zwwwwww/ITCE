/*
From:ITC
5
Numerical defects
5.6
Integer sign lost because of unsigned cast
5.6.14
" unsigned int->signed	int	Nonlinear equation"
*/
       
extern int sink;            
void sign_conv_014 ()
{
	int a = 2;
	unsigned int ret;
	ret = (a * a) - 5;/*Tool should detect this line as error*/ /*Integer sign lost because of unsigned cast */
        sink = ret;
}