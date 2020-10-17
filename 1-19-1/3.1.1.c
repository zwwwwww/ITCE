/*
From:ITC
3
Inappropriate code
3.1
Dead code
3.1.1
Constant if statement
*/

extern int sink;
void dead_code_001()
{
	int a = 0;
	int ret;
	if (0)
	{
		a++; /*Tool should detect this line as error*/ /*ERROR:Dead Code*/
	}
	ret = a;
	sink = ret;
}
