/*
From:ITC
5
Numerical defects
5.6
Integer sign lost because of unsigned cast
5.6.12
"unsigned int->signed	int Value of random variable"
*/

extern int sink;     
int rand(void);  
void sign_conv_012 ()
{
	int a;
	unsigned int ret;

	/*            0 rand() 2147483647 RAND_MAX */
	/* 1073741823  rand()  1073741823 1073741824             */
	a = rand() - 1073741823;

	ret = a;/*Tool should detect this line as error*/ /*Integer sign lost because of unsigned cast */
        sink = ret;
}
