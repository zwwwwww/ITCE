/*
From:ITC
8
Stack related defects 
8.3
Stack underrun
8.3.7
floating point underflow ( float )
*/


extern int sink;

void data_underflow_007()
{
	float ret;

	/* 0 00000000 00000000000000000000001 */
	float min = 1.40129846e-45F;

	ret = min / 2.0F; /*Tool should detect this line as error*/ /*ERROR:Data Underflow*/
	sink = ret;
}
"
