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
		a++; /*Tool should detect this line as error*/ /*ERROR:Unintentional end less loop*/
	}
	ret = a;
	sink = ret;
}
