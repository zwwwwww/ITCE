/*
From:ITC
5
Numerical defects
5.5
Integer precision lost because of cast
5.5.3
short-> long
*/
        
extern int sink;              
void data_lost_003 ()
{
	short ret;
	long a = 0x7fff;
	ret = a;/*Tool should Not detect this line as error*/ /*No ERROR:Integer precision lost because of cast*/
        sink = ret;
}
