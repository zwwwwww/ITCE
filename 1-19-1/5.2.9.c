/*
From:ITC
5
Numerical defects
5.2
Data over?ow
5.2.9
overflow in constant (signed) +1 bit field
*/
                           
static int sink;                     
typedef struct {
	signed int max : 5;
	signed int ret : 5;
} data_overflow_009_s_001;

void data_overflow_009 ()
{
	data_overflow_009_s_001 s;
	s.max = 0x0f;
	s.ret = s.max + 1;/*Tool should detect this line as error*/ /*ERROR:Data Overflow*/
}