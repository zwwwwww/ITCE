/*
From:ITC
4
Misc defects
4.2
Non void function does not return value 
4.2.1
 it contains if statements
*/

int rand(void);
extern int sink;
int not_return_001_func_001(int flag)
{
	if (flag == 0)
	{
		return 0;
	}
} /*Tool should detect this line as error*/ /*ERROR: No return value */

void not_return_001()
{
	int ret;
	ret = not_return_001_func_001(rand());
	sink = ret;
}
