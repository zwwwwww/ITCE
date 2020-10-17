/*
From:ITC
5
Numerical defects
5.5
Integer precision lost because of cast
5.5.4
int->float
*/
              
extern int sink;                   
void data_lost_004 ()
{
	int ret;
	float a = 2.14748365e+09F; /* 0x80000000 */
	ret = a;/*Tool should detect this line as error*/ /*ERROR:Integer precision lost because of cast*/
        sink = ret;
}