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
	unsigned int a = 0xffff;
	ret = a;/*Tool should Not detect this line as error*/ /*No ERROR:Integer precision lost because of cast*/
        sink = ret;
}
