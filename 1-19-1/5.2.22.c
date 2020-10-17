/*
From:ITC
5
Numerical defects
5.2
Data over?ow
5.2.22
int Overflow at Also known as double
*/
              
static int sink;                 
void data_overflow_022 ()
{
	int max = 0x7fffffff;
	int d = 1;
	int d1;
	int d2;
	int ret;
	d1 = d;
	d2 = d1;
	ret = max + d2; /*Tool should detect this line as error*/ /*ERROR:Data Overflow*/
        sink = ret;
}