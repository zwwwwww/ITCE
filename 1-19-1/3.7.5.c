/*
From:ITC
3
Inappropriate code
3.7
Contradict conditions 
3.7.5
" conditional operator	(a==0&&a==1)"
*/

int rand(void);
extern int sink;
void conflicting_cond_005()
{
	int a;
	int b;
	int ret;

	a = rand();
	b = ((a == 0) && (a == 1)) ? 0 : 1; /*Tool should detect this line as error*/ /*ERROR:contradict condition*/
	ret = b;
	sink = ret;
}
