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
        snprintf(buf1, 100 - strlen(STR) - 1, " % s\n ", STR); /*Tool should detect this line as error*/ /*ERROR:Return value of function never checked*/
    }
}
