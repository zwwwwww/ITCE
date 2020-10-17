/*
From:ITC
3
Inappropriate code
3.5
Return value of function never checked
3.5.5
"Function called in a for loop,"
*/

typedef struct
{
	float c;
	char *a;
	int b;
} function_return_value_unchecked_005_s_001;

function_return_value_unchecked_005_s_001 function_return_value_unchecked_005_s_001_func_001()
{
	function_return_value_unchecked_005_s_001 u1;
	char *s = " This is STR ";
	u1.a = s;
	u1.b = 20;
	u1.c = 30.5;
	return u1;
}
void function_return_value_unchecked_005()
{
	function_return_value_unchecked_005_s_001 u;
	int i;
	for (i = 0; i < 10; i++)
	{
		u = function_return_value_unchecked_005_s_001_func_001(); /*Tool should detect this line as error*/ /*ERROR:Return value of function never checked*/
		if (i == 5)
			if (u.b > 0)
				u.c = 60.5;
	}
}
