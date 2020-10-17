/*
From:ITC
4
Misc defects
4.3
Uninitialized variable 
4.3.14
structure int Function arguments
*/

typedef struct
{
	int a;
	int b;
	int uninit;
} uninit_var_014_s_001;

uninit_var_014_s_001 uninit_var_014_func_001(uninit_var_014_s_001 s1)
{
	uninit_var_014_s_001 ret;
	ret.a = (++s1.a);
	ret.b = (++s1.b);
	ret.uninit = (++s1.uninit); /*Tool should detect this line as error*/ /*ERROR:Uninitialized Variable*/
	return ret;
}

void uninit_var_014()
{
	uninit_var_014_s_001 s, r;
	s.a = 1;
	s.b = 1;
	r = uninit_var_014_func_001(s);
}
