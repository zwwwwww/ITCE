/*
From:ITC
3
Inappropriate code
3.5
Return value of function never checked
3.5.1
returned value is assigned variable but never used after that
*/
int function_return_value_unchecked_001_func_001(int flag)
{
	int ret;
	if (flag == 0)
		ret = 0;
	else
		ret = flag++;
	return ret;
}
int function_return_value_unchecked_001_func_002(int flag)
{
	int temp;
	temp = function_return_value_unchecked_001_func_001(flag);
	if (temp > 0)
	{
		temp = temp + 50;
	}
	else
		temp = 0;
	return temp;
}
void function_return_value_unchecked_001()
{
	int a;
	a = function_return_value_unchecked_001_func_002(1); /*Tool should detect this line as error*/ /*ERROR:Return value of function never checked*/
	a++;
}
