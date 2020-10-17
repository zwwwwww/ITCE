/*
From:ITC
3
Inappropriate code
3.7
Contradict conditions 
3.7.7
" while statement	(a==0&&a==1)"
*/

int rand(void);
extern int sink;
void conflicting_cond_007()
{
	int a;
	int b = 0;
	int ret;

	a = rand();
	while ((a == 0) && (a == 1)) /*Tool should detect this line as error*/ /*ERROR:contradict condition*/
	{
		b += a;
		a++;
	}
	ret = b;
	sink = ret;
}
