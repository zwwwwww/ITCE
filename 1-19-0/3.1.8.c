/*
From:ITC
3
Inappropriate code
3.1
Dead code
3.1.8
constant while statement
*/

extern int sink;
void dead_code_008()
{
	int a = 0;
	int ret;
	while (1)
	{
		a++; /*Tool should not detect this line as error*/ /*No ERROR:Dead Code*/
		break;
	}
	ret = a;
	sink = ret;
}
