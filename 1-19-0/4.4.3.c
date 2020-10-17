/*
From:ITC
4
Misc defects
4.4
Unintentional end less loop
4.4.3
"while statement	Constant"
*/

extern int sink;
void endless_loop_003()
{
	int ret;
	int a = 0;
	while (1)
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
