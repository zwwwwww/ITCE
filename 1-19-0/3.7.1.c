/*
From:ITC
3
Inappropriate code
3.7
Contradict conditions 
3.7.1
"the if statement	(a==0&&a==1)"
*/

int rand(void);
extern int sink;
void conflicting_cond_001()
{
	int a;
	int b = 0;
	int ret;

	a = rand();
	if ((a == 0) || (a == 1)) /*Tool should Not detect this line as error*/ /*No ERROR:contradict condition*/
	{
		b += a;
	}
	ret = b;
	sink = ret;
}
