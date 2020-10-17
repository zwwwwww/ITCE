/*
From:ITC
4
Misc defects
4.2
Non void function does not return value 
4.2.2
it contains nested if statements
*/

int rand(void);
extern int sink;
int not_return_002_func_001(int flag1, int flag2)
{
	if (flag1 == 0)
	{
		if (flag2 == 0)
		{
			return 0;
		}
		return 1; /*Tool should not detect this line as error*/ /*No ERROR: No return value */
	}
	else
	{
		return 0;
	}
}

void not_return_002()
{
	int ret;
	ret = not_return_002_func_001(rand(), rand());
	sink = ret;
}
