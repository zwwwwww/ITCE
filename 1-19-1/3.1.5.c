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
	int flag = 0;
	int a = 0;
	int ret;
	if (flag > 0)
	{
		a++; /*Tool should  detect this line as error*/ /* ERROR:Dead Code*/
	}
	ret = a;
	sink = ret;
}
