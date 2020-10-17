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
	if (1)
	{
		a++; /*Tool should not detect this line as error*/ /*No ERROR:Dead Code*/
	}
	ret = a;
	sink = ret;
}
