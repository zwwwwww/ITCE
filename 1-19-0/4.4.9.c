/*
From:ITC
4
Misc defects
4.4
Unintentional end less loop
4.4.9
"do-while statement	Constant"
*/

extern int sink;
void endless_loop_009()
{
	int ret;
	int a = 0;
	do
	{
		a++;
		if (a > 5)
		{
			break;
		}
	} while (1); /*Tool should Not detect this line as error*/ /*No ERROR:Unintentional end less loop*/
	ret = a;
	sink = ret;
}
