/*
From:ITC
3
Inappropriate code
3.4
Redundant conditions
3.4.1
"the if statement	(5<a&&10<a)"
*/
#include <stdio.h>
int rand(void);
extern int sink;
void redundant_cond_001()
{
	int a;
	int b = 0;
	int ret;

	a = rand();
	if ((5 < a) && (10 < a)) /*Tool should detect this line as error*/ /*ERROR:Redundant condition*/
	{
		b += a;
	}
	ret = b;
	sink = ret;
}
