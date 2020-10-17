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
	float a = 2.14748352e+09F; /* 0x7fffff80 */
	ret = a;/*Tool should Not detect this line as error*/ /*No ERROR:Integer precision lost because of cast*/
        sink = ret;
}
