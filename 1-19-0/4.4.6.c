/*
From:ITC
4
Misc defects
4.4
Unintentional end less loop
4.4.6
while statement Function arguments
*/

extern int sink;
void endless_loop_006_func_001(int flag)
{
	int ret;
	int a = 0;
	while (flag)
	{
		a++; /*Tool should Not detect this line as error*/ /*No ERROR:Unintentional end less loop*/
		if (a > 5)
		{
			break;
		}
	}
	ret = a;
	sink = ret;
}

void endless_loop_006()
{
	endless_loop_006_func_001(1);
}
