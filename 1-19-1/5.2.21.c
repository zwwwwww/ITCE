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
	int max = 0x7fffffff;
	int d = 1;
	int d1;
	int ret;
	d1 = d;
	ret = max + d1; /*Tool should detect this line as error*/ /*ERROR:Data Overflow*/
        sink = ret;
}