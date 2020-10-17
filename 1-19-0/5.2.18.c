/*
From:ITC
5
Numerical defects
5.2
Data over?ow
5.2.18
int Overflow at The return value of the function
*/
                                                                                      
static int sink;                                                                                                  
int data_overflow_018_func_001 ()
{
	return 1;
}

void data_overflow_018 ()
{
	int max = 0x7ffffffe;
	int ret;
	ret = max + data_overflow_018_func_001();/*Tool should Not detect this line as error*/ /*No ERROR:Data Overflow*/
        sink = ret;
}
