/*
From:ITC
3
Inappropriate code
3.1
Dead code
3.1.11
"while statement	Function arguments"
*/

extern int sink;
void dead_code_011_func_001(int flag)
{
	int a = 0;
	int ret;
	while (flag)
	{
		a++; /*Tool should not detect this line as error*/ /*No ERROR:Dead Code*/
		break;
	}
	ret = a;
	sink = ret;
}

void dead_code_011()
{
	dead_code_011_func_001(1);
}
