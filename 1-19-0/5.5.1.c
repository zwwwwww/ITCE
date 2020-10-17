/*
From:ITC
5
Numerical defects
5.5
Integer precision lost because of cast
5.5.1
" char	-> short"
*/
 
extern int sink;       
void data_lost_001 ()
{
	char ret;
	short a = 0x7f;
	ret = a; /*Tool should Not detect this line as error*/ /*No ERROR:Integer precision lost because of cast*/
        sink = ret;
}
