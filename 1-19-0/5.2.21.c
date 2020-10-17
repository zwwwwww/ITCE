/*
From:ITC
5
Numerical defects
5.2
Data over?ow
5.2.21
int Overflow at Alias for 1 weight
*/
              
static int sink;                    
void data_overflow_021 ()
{
	int max = 0x7ffffffe;
	int d = 1;
	int d1;
	int ret;
	d1 = d;
	ret = max + d1;/*Tool should Not detect this line as error*/ /*No ERROR:Data Overflow*/
        sink = ret;
}
