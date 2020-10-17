/*
From:ITC
5
Numerical defects
5.5
Integer precision lost because of cast
5.5.1
" char	-> short"
*/                                                                                      
void data_lost_001 ()
{
	char ret;
	short a = 0x80;
	ret = a;/*Tool should detect this line as error*/ /*ERROR:Integer precision lost because of cast*/
        sink = ret;
}