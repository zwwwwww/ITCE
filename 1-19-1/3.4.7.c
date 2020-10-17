/*
From:ITC
3
Inappropriate code
3.4
Redundant conditions
3.4.7
"conditional operator	(5<a&&10<a)"
*/
#include <stdio.h>
int rand(void);
extern int sink;
void redundant_cond_007()
{
	int a;
	int b;
	int ret;

	a = rand();
	b = ((5 < a) && (10 < a)) ? 0 : 1; /*Tool should detect this line as error*/ /*ERROR:Redundant condition*/
	ret = b;
	sink = ret;
}
