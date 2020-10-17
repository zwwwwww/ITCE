/*
From:ITC
3
Inappropriate code
3.7
Contradict conditions 
3.7.2
"the if statement	(a<5&&10<a)"
*/

int rand(void);
extern int sink;
void conflicting_cond_002()
{
	int a;
	int b = 0;
	int ret;

	a = rand();
	if (!((a < 5) || (10 < a))) /*Tool should Not detect this line as error*/ /*No ERROR:contradict condition*/
	{
		b += a;
	}
	ret = b;
	sink = ret;
}
