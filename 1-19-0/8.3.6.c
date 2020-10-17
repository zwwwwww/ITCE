/*
From:ITC
8
Stack related defects 
8.3
Stack underrun
8.3.6
 the operands is a constant
*/


extern int sink;

void data_underflow_006()
{
	int ret;
	ret = (-2147483646) - 2; /*Tool should Not detect this line as error*/ /*No ERROR:Data Underflow*/
	sink = ret;
}
"
