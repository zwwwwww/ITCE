/*
From:ITC
5
Numerical defects
5.2
Data over?ow
5.2.20
"int Overflow at	An array of element values"
*/
                                                                                      
static int sink;                                                                                                
void data_overflow_020 ()
{
	int max = 0x7ffffffe;
	int dlist[4] = {4, 1, 3, 2};
	int ret;
	ret = max + dlist[1];/*Tool should Not detect this line as error*/ /*No ERROR:Data Overflow*/
        sink = ret;
}
