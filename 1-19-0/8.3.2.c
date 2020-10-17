/*
From:ITC
8
Stack related defects 
8.3
Stack underrun
8.3.2
"unsigned int	Underflow with -1	Constant"
*/


extern int sink;

void data_underflow_002()
{
	unsigned int min = 1;
	unsigned int ret;
	ret = min - 1; /*Tool should Not detect this line as error*/ /*No ERROR:Data Underflow*/
	sink = ret;
}
"
