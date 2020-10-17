/*
From:ITC
5
Numerical defects
5.5
Integer precision lost because of cast
5.5.11
short->int
*/
      
extern int sink;   
void data_lost_011 ()
{
	short ret;
	ret = 0x8000;/*Tool should detect this line as error*/ /*ERROR:Integer precision lost because of cast*/
        sink = ret;
}
