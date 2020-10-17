/*
From:ITC
5
Numerical defects
5.2
Data over?ow
5.2.10
overflow in constant (unsigned) +1 bit field
*/
                                                                                     
static int sink;                                                                                             
typedef struct {
	unsigned int max : 5;
	unsigned int ret : 5;
} data_overflow_010_s_001;

void data_overflow_010 ()
{
	data_overflow_010_s_001 s;
	s.max = 0x1e;
	s.ret = s.max + 1;/*Tool should Not detect this line as error*/ /*No ERROR:Data Overflow*/
}
