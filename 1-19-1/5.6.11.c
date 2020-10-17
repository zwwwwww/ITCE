/*
From:ITC
5
Numerical defects
5.6
Integer sign lost because of unsigned cast
5.6.11
unsigned int->signed int
*/
  
extern int sink;     
void sign_conv_011 ()
{
	unsigned int ret;
	ret = -1;/*Tool should detect this line as error*/ /*Integer sign lost because of unsigned cast */
        sink = ret;
}
