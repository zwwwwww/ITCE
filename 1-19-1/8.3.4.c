/*
From:ITC
8
Stack related defects 
8.3
Stack underrun
8.3.4
"int	underflow with -128 Constant"
*/


extern int sink;

void data_underflow_004()
{
	int min = -2147483521;
	int ret;
	ret = min - 128; /*Tool should detect this line as error*/ /*ERROR:Data Underflow*/
	sink = ret;
}
"
