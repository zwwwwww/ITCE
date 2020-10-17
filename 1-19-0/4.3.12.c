/*
From:ITC
4
Misc defects
4.3
Uninitialized variable 
4.3.12
Structure passed as function parameter and based on the return value of function another structure is initialized
*/

extern int sink;
typedef struct
{
	unsigned int a;
	unsigned int b;
	unsigned int uninit;
} uninit_var_012_s_001;

int uninit_var_012_func_001(uninit_var_012_s_001 s1)
{
	switch ((s1.a + s1.b + s1.uninit)) /*Tool should not detect this line as error*/ /*No ERROR:Uninitialized Variable*/
	{
	case 5:
	{
		return 5;
	}
	case 6:
	{
		return 6;
	}
	case 7:
	{
		return 7;
	}
	default:
		return -1;
	}
}

void uninit_var_012()
{
	uninit_var_012_s_001 s, r;
	s.a = 2;
	s.b = 1;
	s.uninit = 2;
	int ret;
	ret = uninit_var_012_func_001(s);
	if (ret >= 0)
		r = s;
	r.a = 0;
	sink = r.a;
}
