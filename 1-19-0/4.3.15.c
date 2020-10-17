/*
From:ITC
4
Misc defects
4.3
Uninitialized variable 
4.3.15
Array initialized in a  function using macro's
*/

extern int sink;
#define ZERO 0
#define ONE 1
#define TWO 2
void uninit_var_015_func_001(int a[])
{
	a[0] = ZERO;
	a[1] = ONE;
	a[2] = TWO;
}

void uninit_var_015()
{
	int a[3];
	uninit_var_015_func_001(a); /*Tool should not detect this line as error*/ /*No ERROR:Uninitialized Variable*/
}
