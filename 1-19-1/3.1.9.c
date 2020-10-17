/*
From:ITC
3
Inappropriate code
3.1
Dead code
3.1.9
variable while statement
*/

extern int sink;
void dead_code_009()
{
	int flag = 0;
	int a = 0;
	int ret;
	while (flag)
	{
		a++; /*Tool should detect this line as error*/ /*ERROR:Dead Code*/
		break;
	}
	ret = a;
	sink = ret;
}
