/*
From:ITC
4
Misc defects
4.4
Unintentional end less loop
4.4.5
while statement The return value of the function
*/

extern int sink;
int endless_loop_005_func_001()
{
	return 1;
}

void endless_loop_005()
{
	int ret;
	int a = 0;
	while (endless_loop_005_func_001())
	{ /*Tool should Not detect this line as error*/ /*No ERROR:Unintentional end less loop*/
		a++;
		if (a > 5)
		{
			break;
		}
	}
	ret = a;
	sink = ret;
}
