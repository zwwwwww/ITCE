/*
From:ITC
5
Numerical defects
5.5
Integer precision lost because of cast
5.5.9
"unsigned shor->	unsigned long"
*/
                   
extern int sink;                         
void data_lost_009 ()
{
	unsigned short ret;
	unsigned long a = 0x00010000;
	ret = a;/*Tool should detect this line as error*/ /*ERROR:Integer precision lost because of cast*/
        sink = ret;
}