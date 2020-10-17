/*
From:ITC
3
Inappropriate code
3.4
Redundant conditions
3.4.6
"the if statement	nested if statement ( if (a < 5) if(a<10))"
*/
#include <stdio.h>
int rand(void);
extern int sink;
void redundant_cond_006()
{
	int a;
	int b = 0;
	int ret;

	a = rand();
	if (a < 5)
	{
		if (a < 10) /*Tool should detect this line as error*/ /*ERROR:Redundant condition*/
		{
			b += a;
		}
	}
	ret = b;
	sink = ret;
}
