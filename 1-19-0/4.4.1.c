/*
From:ITC
4
Misc defects
4.4
Unintentional end less loop
4.4.1
the for statement No ongoing condition equation
*/

extern int sink;
void endless_loop_001()
{
	int ret;
	int a = 0;
	int i;
	for (i = 0;; i++)
	{
		a++; /*Tool should Not detect this line as error*/ /*No ERROR:Unintentional end less loop*/
		if (i > 5)
		{
			break;
		}
	}
	ret = a;
	sink = ret;
}
