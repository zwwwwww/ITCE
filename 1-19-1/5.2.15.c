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
	int max = 0x7fffffff;
	int d;
	int ret;
	d = rand();
	ret = max + d; /*Tool should detect this line as error*/ /*ERROR:Data Overflow*/
        sink = ret;
}