/*
From:ITC
3
Inappropriate code
3.7
Contradict conditions 
3.7.10
"do-while statement	(a==0&&a==1)"
*/

int rand(void);
extern int sink;
void conflicting_cond_010()
{
	int a;
	int ret;

	do
	{
		a = rand();
	} while ((a == 0) && (a == 1)); /*Tool should detect this line as error*/ /*ERROR:contradict condition*/
	ret = a;
	sink = ret;
}
