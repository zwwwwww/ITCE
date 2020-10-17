/*
From:ITC
3
Inappropriate code
3.5
Return value of function never checked
3.5.16
Function called in a for loop but only one return value evaluated in a if condition and all elements of structure is evaluated
*/

typedef struct
{
	float c;
	char *a;
	int b;
} function_return_value_unchecked_016_s_001;

function_return_value_unchecked_016_s_001 function_return_value_unchecked_016_s_001_func_001()
{
	function_return_value_unchecked_016_s_001 u1;
	char *s = " This is STR ";
	u1.a = s;
	u1.b = 20;
	u1.c = 30.5;
	return u1;
}
void function_return_value_unchecked_016()
{
	function_return_value_unchecked_016_s_001 u;
	int i = 0;
	for (; i < 10; i++)
	{
		u = function_return_value_unchecked_016_s_001_func_001(); /*Tool should not detect this line as error*/ /*No ERROR:Return value of function never checked*/
		if (u.b > 0 && u.a != NULL && u.c != 0)
			u.c = 60.5;
	}
}
