/*
From:ITC
5
Numerical defects
5.2
Data over?ow
5.2.15
"int	Overflow at Value of random variable + 1"
*/
       
static int sink;           
int rand(void);           
void data_overflow_015 ()
{
	int max = 0x7ffffffe;
	int d;
	int ret;
	d = rand() % 2;
	ret = max + d;/*Tool should Not detect this line as error*/ /*No ERROR:Data Overflow*/
        sink = ret;
}
