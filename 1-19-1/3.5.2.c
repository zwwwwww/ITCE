/*
From:ITC
3
Inappropriate code
3.5
Return value of function never checked
3.5.2
returned value is unchecked
*/

float function_return_value_unchecked_002_func_001(int flag)
{
   float ret = 1.0;
   while (flag > 0)
   {
      ret++;
      flag--;
   }
   return ret;
}
void function_return_value_unchecked_002()
{
   float a = 0.0;
   function_return_value_unchecked_002_func_001(10); /*Tool should detect this line as error*/ /*ERROR:Return value of function never checked*/
   if (a > 0)
      a--;
}
