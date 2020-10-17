/*
From:ITC
5
Numerical defects
5.5
Integer precision lost because of cast
5.5.6
float->double
*/
              
extern int sink;                 
void data_lost_006 ()
{
	float ret;	/* MAX:2^127 * (2 - 2^(-23)) */
	double a = 3.4028232635611926e+38;	/* 2^127 * (2 - 2^(-23)) */
        // JDR: next line is a lossy cast!
	ret = a;/*Tool should Not detect this line as error*/ /*No ERROR:Integer precision lost because of cast*/
        sink = ret;
}
