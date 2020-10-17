/*
From:ITC
5
Numerical defects
5.6
Integer sign lost because of unsigned cast
5.6.18
"unsigned int->signed	int	Alias for 1 weight"
*/
         
extern int sink;          
void sign_conv_018 ()
{
	int a = -1;
	int a1;
	unsigned int ret;
	a1 = a;
	ret = a1;/*Tool should detect this line as error*/ /*Integer sign lost because of unsigned cast */
        sink = ret;
}