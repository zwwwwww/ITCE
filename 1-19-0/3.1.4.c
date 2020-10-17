/*
From:ITC
3
Inappropriate code
3.1
Dead code
3.1.4
"if statement	Function arguments"
*/
void dead_code_004_func_001(int flag)
{
	int a = 0;
	int ret;
	if (flag)
	{
		a++; /*Tool should not detect this line as error*/ /*No ERROR:Dead Code*/
	}
	ret = a;
	sink = ret;
}

void dead_code_004()
{
	dead_code_004_func_001(1);
}
