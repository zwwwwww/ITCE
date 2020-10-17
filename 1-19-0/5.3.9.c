/*
From:ITC
5
Numerical defects
5.3
Data under?ow
5.3.9
underflow (char)
*/
        
extern int sink;                 
void data_underflow_009 ()
{
	char min = -126;	/* 0x80000002 */
	char ret;
	ret = min - 2; /*Tool should Not detect this line as error*/ /*No ERROR:Data Underflow*/
        sink = ret;
}
