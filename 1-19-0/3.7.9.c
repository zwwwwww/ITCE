/*
From:ITC
3
Inappropriate code
3.7
Contradict conditions 
3.7.9
"while statement	((0<a&&a<2)&&(8<a&&a<10))"
*/

int rand(void);
extern int sink;
void conflicting_cond_009()
{
	int a;
	int b = 0;
	int ret;

	a = rand();
	while (((0 < a) && (a < 2)) || ((8 < a) && (a < 10))) /*Tool should Not detect this line as error*/ /*No ERROR:contradict condition*/
	{
		b += a;
		a++;
	}
	ret = b;
	sink = ret;
}
