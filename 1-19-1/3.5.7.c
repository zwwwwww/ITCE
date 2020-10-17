/*
From:ITC
3
Inappropriate code
3.5
Return value of function never checked
3.5.7
Data type of the Returned value and the realistic variable is different 
*/
float function_return_value_unchecked_007_func_001()
{
	float ret = 10.034;
	return (ret);
}
void function_return_value_unchecked_007()
{

	int i = function_return_value_unchecked_007_func_001(); /*Tool should detect this line as error*/ /*ERROR:Return value of function never checked*/
																									  //if (i<10)
	i++;
}
