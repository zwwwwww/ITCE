/*
From:ITC
3
Inappropriate code
3.1
Dead code
3.1.2
the if statement variable
*/

extern int sink;
void dead_code_002()
{
	int flag = 0;
	int a = 0;
	int ret;
	if (flag)
	{
		a++; /*Tool should detect this line as error*/ /*ERROR:Dead Code*/
	}
	ret = a;
	sink = ret;
}
