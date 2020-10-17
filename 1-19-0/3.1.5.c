/*
From:ITC
3
Inappropriate code
3.1
Dead code
3.1.5
statement expression if (a <b)
*/

extern int sink;
void dead_code_005()
{
	int flag = 1;
	int a = 0;
	int ret;
	if (flag > 0)
	{
		a++; /*Tool should not detect this line as error*/ /*No ERROR:Dead Code*/
	}
	ret = a;
	sink = ret;
}
