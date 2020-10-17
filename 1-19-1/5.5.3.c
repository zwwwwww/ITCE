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
	long a = 0x8000;
	ret = a;/*Tool should detect this line as error*/ /*ERROR:Integer precision lost because of cast*/
        sink = ret;
}