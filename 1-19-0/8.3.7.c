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

	/* 0 00000000 00000000000000000000010 */
	float min = 2.80259693e-45F;

	ret = min / 2.0F; /*Tool should Not detect this line as error*/ /*No ERROR:Data Underflow*/
	sink = ret;
}
"
