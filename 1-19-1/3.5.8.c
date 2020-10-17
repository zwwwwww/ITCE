/*
From:ITC
3
Inappropriate code
3.5
Return value of function never checked
3.5.8
Parameters passed is different from function definition
*/

double function_return_value_unchecked_008_func_001(int a)
{
	double ret = 9.034;
	ret += a;
	return (ret);
}
void function_return_value_unchecked_008()
{
	int i = function_return_value_unchecked_008_func_001(6.00); /*Tool should detect this line as error*/ /*ERROR:Return value of function never checked*/
																										  //if (i<10)
	i++;
}
