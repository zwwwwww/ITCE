/*
From:ITC
3
Inappropriate code
3.1
Dead code
3.1.7
constant for statement
*/

extern int sink;
void dead_code_007()
{
	int a = 0;
	int i;
	int ret;
	for (i = 0; i <= 1; i++)
	{
		a++; /*Tool should not detect this line as error*/ /*No ERROR:Dead Code*/
		break;
	}
	ret = a;
	sink = ret;
}
