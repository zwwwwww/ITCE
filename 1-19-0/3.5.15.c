/*
From:ITC
3
Inappropriate code
3.5
Return value of function never checked
3.5.15
using a puts function in switch case
*/

void function_return_value_unchecked_015()
{
    int flag = 6, i = 10;
    switch (flag)
    {
    case 6:
        if (puts(" TEST ") == EOF) /*Tool should not detect this line as error*/ /*No ERROR:Return value of function never checked*/
        {
            i = 20;
        }
        break;
    default:
    {
        i = 10;
        break;
    }
    }
    sink = i;
}
