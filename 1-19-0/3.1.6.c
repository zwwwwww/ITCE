/*
From:ITC
3
Inappropriate code
3.1
Dead code
3.1.6
"the if statement	(a == b)"
*/

extern int sink;
void dead_code_006()
{
	int flag = 0;
	int a = 0;
	int ret;
	if (flag == 0)
	{
		a++; /*Tool should not detect this line as error*/ /*No ERROR:Dead Code*/
	}
	ret = a;
	sink = ret;
}
