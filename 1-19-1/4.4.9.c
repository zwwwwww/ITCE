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
		a++; /*Tool should detect this line as error*/ /*ERROR:Unintentional end less loop*/
	} while (1);
	ret = a;
	sink = ret;
}
