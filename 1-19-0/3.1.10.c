/*
From:ITC
3
Inappropriate code
3.1
Dead code
3.1.10
The return value of the function while statement
*/

extern int sink;
int dead_code_010_func_001()
{
	return 1;
}

void dead_code_010()
{
	int a = 0;
	int ret;
	while (dead_code_010_func_001())
	{
		a++; /*Tool should not detect this line as error*/ /*No ERROR:Dead Code*/
		break;
	}
	ret = a;
	sink = ret;
}
