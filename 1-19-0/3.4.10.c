/*
From:ITC
3
Inappropriate code
3.4
Redundant conditions
3.4.10
"while statement	(a<5&&a<10)"
*/

int rand(void);
extern int sink;
void redundant_cond_010()
{
	int a;
	int b = 0;
	int ret;

	a = rand();
	while ((a < 5)) /*Tool should not detect this line as error*/ /*No ERROR:Redundant condition*/
	{
		b += a;
		a++;
	}
	ret = b;
	sink = ret;
}
