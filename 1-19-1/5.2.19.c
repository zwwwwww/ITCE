/*
From:ITC
5
Numerical defects
5.2
Data over?ow
5.2.19
int Overflow at Function arguments
*/
      
static int sink;             
void data_overflow_019_func_001 (int d)
{
	int max = 0x7fffffff;
	int ret;
	ret = max + d; /*Tool should detect this line as error*/ /*ERROR:Data Overflow*/
        sink = ret;
}

void data_overflow_019 ()
{
	data_overflow_019_func_001(1);
}