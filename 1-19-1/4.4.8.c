/*
From:ITC
4
Misc defects
4.4
Unintentional end less loop
4.4.8
" while statement	(a==b)"
*/

extern int sink;
void endless_loop_008()
{
	int ret;
	int a = 0;
	int flag = 0;
	while (flag == 0)
	{
		a++; /*Tool should detect this line as error*/ /*ERROR:Unintentional end less loop*/
	}
	ret = a;
	sink = ret;
}
