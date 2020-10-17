/*
From:ITC
3
Inappropriate code
3.5
Return value of function never checked
3.5.3
 Return value evaluated only in a if condition 
*/

char function_return_value_unchecked_003_func_001(void)
{
	char str1 = 'a';
	return str1;
}
void function_return_value_unchecked_003()
{
	int a = 1;
	char buf = function_return_value_unchecked_003_func_001(); /*Tool should detect this line as error*/ /*ERROR:Return value of function never checked*/
	a--;
	if (a != 0)
	{
		if (buf != '\0')
			printf(" % c\n ", buf);
	}
}
