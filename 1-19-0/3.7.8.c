/*
From:ITC
3
Inappropriate code
3.7
Contradict conditions 
3.7.8
"while statement	(a<5&&10<a)"
*/

int rand(void);
extern int sink;
void conflicting_cond_008()
{
	int a;
	int b = 0;
	int ret;

	a = rand();
	while (!((a < 5) || (10 < a))) /*Tool should Not detect this line as error*/ /*No ERROR:contradict condition*/
	{
		b += a;
		a++;
	}
	ret = b;
	sink = ret;
}
