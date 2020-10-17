/*
From:ITC
3
Inappropriate code
3.7
Contradict conditions 
3.7.6
"the for statement	(a==0&&a==1)"
*/

int rand(void);
extern int sink;
void conflicting_cond_006()
{
	int a;
	int b = 0;
	int ret;

	for (a = 0; (a == 0) || (a == 1); a++) /*Tool should Not detect this line as error*/ /*No ERROR:contradict condition*/
	{
		b += a;
	}
	ret = b;
	sink = ret;
}
