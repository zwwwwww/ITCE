/*
From:ITC
5
Numerical defects
5.5
Integer precision lost because of cast
5.5.8
"unsigned shor->	unsigned int "
*/
                        
extern int sink;                     
void data_lost_008 ()
{
	unsigned short ret;
	unsigned int a = 0x00010000;
	ret = a;/*Tool should detect this line as error*/ /*ERROR:Integer precision lost because of cast*/
        sink = ret;
}
