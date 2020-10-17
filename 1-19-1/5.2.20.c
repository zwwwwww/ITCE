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
	int max = 0x7fffffff;
	int dlist[4] = {0, 1, -2, -1};
	int ret;
	ret = max + dlist[1]; /*Tool should detect this line as error*/ /*ERROR:Data Overflow*/
        sink = ret;
}