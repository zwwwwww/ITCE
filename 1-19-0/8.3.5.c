/*
From:ITC
8
Stack related defects 
8.3
Stack underrun
8.3.5
"int	Multiply by underflow	Constant"
*/


extern int sink;

void data_underflow_005()
{
	int min = -1073741824; /* 0xc0000000 */
	int ret;
	ret = min * 2; /*Tool should Not detect this line as error*/ /*No ERROR:Data Underflow*/
	sink = ret;
}
"
