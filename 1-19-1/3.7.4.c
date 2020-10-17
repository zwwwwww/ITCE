/*
From:ITC
3
Inappropriate code
3.7
Contradict conditions 
3.7.4
"the if statement	nested if statement ( if (a < 5) if(10<a))"
*/

int rand(void);
extern int sink;
void conflicting_cond_004()
{
	int a;
	int b = 0;
	int ret;

	a = rand();
	if (a < 5)
	{
		if (10 < a) /*Tool should detect this line as error*/ /*ERROR:contradict condition*/
		{
			b += a;
		}
	}
	ret = b;
	sink = ret;
}
