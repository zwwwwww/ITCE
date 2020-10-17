/*
From:ITC
5
Numerical defects
5.5
Integer precision lost because of cast
5.5.17
" a short	int->An array of element values"
*/
     
extern int sink;        
void data_lost_017 ()
{
	short ret;
	int buf[5] = {0x0111, 0x0001, 0x0011, 0x8000, 0x1111};
	ret = buf[3];/*Tool should detect this line as error*/ /*ERROR:Integer precision lost because of cast*/
        sink = ret;
}
