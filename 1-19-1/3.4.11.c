/*
From:ITC
3
Inappropriate code
3.4
Redundant conditions
3.4.11
"while statement	((0<a&&a<10)&&(2<a&&a<8))"
*/

int rand(void);
extern int sink;
void redundant_cond_011()
{
	int a;
	int b = 0;
	int ret;

	a = rand();
	while (((0 < a) && (a < 10)) && ((2 < a) && (a < 8))) /*Tool should detect this line as error*/ /*ERROR:Redundant condition*/
	{
		b += a;
		a++;
	}
	ret = b;
	sink = ret;
}
