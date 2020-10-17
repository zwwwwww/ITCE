/*
From:ITC
5
Numerical defects
5.5
Integer precision lost because of cast
5.5.2
short-> int
*/
                              
extern int sink;                                 
void data_lost_002 ()
{
	short ret;
	int a = 0x8000;
	ret = a;/*Tool should detect this line as error*/ /*ERROR:Integer precision lost because of cast*/
        sink = ret;
}