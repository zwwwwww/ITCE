/*
From:ITC
4
Misc defects
4.2
Non void function does not return value 
4.2.3
it contains including switch
*/

int rand(void);
extern int sink;
int not_return_003_func_001(int flag)
{
	switch (flag)
	{
	case 1:
		return 0;
	case 2:
		break;
	case 3:
		return 0;
	default:
		return -1;
	}
} /*Tool should detect this line as error*/ /*ERROR: No return value */

void not_return_003()
{
	int ret;
	ret = not_return_003_func_001(rand());
	sink = ret;
}
