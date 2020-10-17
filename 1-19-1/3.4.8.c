/*
From:ITC
3
Inappropriate code
3.4
Redundant conditions
3.4.8
 the for statement (5<a&&10<a)
*/
#include <stdio.h>
int rand(void);
extern int sink;
void redundant_cond_008()
{
	int a;
	int b = 0;
	int ret;

	for (a = 20; (5 < a) && (10 < a); a--) /*Tool should detect this line as error*/ /*ERROR:Redundant condition*/
	{
		b += a;
	}
	ret = b;
	sink = ret;
}
