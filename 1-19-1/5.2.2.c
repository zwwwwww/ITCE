/*
From:ITC
5
Numerical defects
5.2
Data over?ow
5.2.2
"Overflow in short + 1	Constant"
*/
         
static int sink;               
void data_overflow_002 ()
{
	short max = 0x7fff;
	short ret;
	ret = max + 1;/*Tool should detect this line as error*/ /*ERROR:Data Overflow*/
        sink = ret;
}