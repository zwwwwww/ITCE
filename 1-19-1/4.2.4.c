/*
From:ITC
4
Misc defects
4.2
Non void function does not return value 
4.2.4
it contains the goto
*/

int rand(void);
extern int sink;
int not_return_004_func_001(int flag)
{
	int ret = 0;
	if (flag == 0)
	{
		goto my_label;
	}
	return ret;
my_label:
	ret++;
} /*Tool should detect this line as error*/ /*ERROR: No return value */

void not_return_004()
{
	int ret;
	ret = not_return_004_func_001(rand());
	sink = ret;
}
