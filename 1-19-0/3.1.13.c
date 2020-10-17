/*
From:ITC
3
Inappropriate code
3.1
Dead code
3.1.13
"while statement	(a == b)"
*/

extern int sink;
void dead_code_013()
{
	int flag = 0;
	int a = 0;
	int ret;
	while (flag == 0)
	{
		a++; /*Tool should not detect this line as error*/ /*No ERROR:Dead Code*/
		break;
	}
	ret = a;
	sink = ret;
}
