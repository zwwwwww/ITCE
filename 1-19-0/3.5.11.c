/*
From:ITC
3
Inappropriate code
3.5
Return value of function never checked
3.5.11
using snprintf in a if condition
*/

#define STR " string "
void function_return_value_unchecked_011()
{
    int k;
    for (k = 0; k < 5; k++)
    {
        char buf[100] = "

#include ";
            char *buf1 = buf;
        if (snprintf(buf1, 100 - strlen(STR) - 1, " % s\n ", STR) > 0) /*Tool should not detect this line as error*/ /*No ERROR:Return value of function never checked*/
        {
            ;
        }
    }
}
