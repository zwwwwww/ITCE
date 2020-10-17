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

	/* 0 <= rand() <= 2147483647 (RAND_MAX) */
	a = rand();

	ret = a; /*Tool should not detect this line as error*/ /*NO ERROR : Integer sign lost because of unsigned cast */
        sink = ret;
}
