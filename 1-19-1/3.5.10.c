/*
From:ITC
3
Inappropriate code
3.5
Return value of function never checked
3.5.10
using fprintf in a if condition with static variable
*/
#define MAX 10
static int function_return_value_unchecked_010_var = MAX;
void function_return_value_unchecked_010()
{
    int a = 10;
    if (function_return_value_unchecked_010_var == MAX)
    {
        fprintf(stdout, " % s\n ", " TEST STRING "); /*Tool should detect this line as error*/ /*ERROR:Return value of function never checked*/
        {
            a++;
        }
    }
    else if (fprintf(stdout, " % s\n ", " STRING ") < 0)
    {
        a--;
    }
}
