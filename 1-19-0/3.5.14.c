/*
From:ITC
3
Inappropriate code
3.5
Return value of function never checked
3.5.14
using a putchar function in a goto label
*/

void function_return_value_unchecked_014()
{
    int a = 10;
    goto label;
label:
    if (putchar((int)'A') == EOF) /*Tool should not detect this line as error*/ /*No ERROR:Return value of function never checked*/
    {
        a = 20;
    }
    sink = a;
}
