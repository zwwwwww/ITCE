/*
From:ITC
3
Inappropriate code
3.5
Return value of function never checked
3.5.4
Return value evaluated only in a switch case statement
*/

typedef struct
{
	char a[20];
	int b;
} function_return_value_unchecked_004_s_001;

function_return_value_unchecked_004_s_001 function_return_value_unchecked_004_s_001_func_001()
{
	function_return_value_unchecked_004_s_001 s1;
	strcpy(s1.a, " STRING ");
	s1.b = 20;
	return s1;
}

void function_return_value_unchecked_004()
{
	function_return_value_unchecked_004_s_001 s;
	s = function_return_value_unchecked_004_s_001_func_001(); /*Tool should detect this line as error*/ /*ERROR:Return value of function never checked*/
	int flag = 10;
	switch (flag)
	{
	case 1:
	{
		if ((strcmp(s.a, " STRING ") == 0))
			s.b++;
		break;
	}
	case 2:
	{
		if ((strcmp(s.a, " STRING1 ") > 0))
			s.b++;
		break;
	}
	case 3:
	{
		if (s.b <= 20)
			s.b--;
		break;
	}
	default:
	{
		break;
	}
	}
}
