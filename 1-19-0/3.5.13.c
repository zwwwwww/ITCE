/*
From:ITC
3
Inappropriate code
3.5
Return value of function never checked
3.5.13
using fputs function inside a if condition evaluated with function return value
*/

int function_return_value_unchecked_013_func_001()
{
    return (1);
}

void function_return_value_unchecked_013()
{
    if (function_return_value_unchecked_013_func_001())
    {
        if (fputs(" STRING #", stdout) == EOF) /*Tool should not detect this line as error*/ /*No ERROR:Return value of function never checked*/
        {
            ;
        }
    }
}
