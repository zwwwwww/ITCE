/*
From:ITC
4
Misc defects
4.3
Uninitialized variable 
4.3.7
structure Int Variable
*/

extern int sink;
typedef struct
{
	int a;
	int b;
	int uninit;
} uninit_var_007_s_001;

void uninit_var_007()
{
	uninit_var_007_s_001 s;
	int ret;
	s.a = 1;
	s.b = 1;
	s.uninit = 1;
	ret = s.uninit; /*Tool should not detect this line as error*/ /*No ERROR:Uninitialized Variable*/
	sink = ret;
}
