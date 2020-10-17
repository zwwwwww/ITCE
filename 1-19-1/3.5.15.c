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
        puts(" TEST "); /*Tool should detect this line as error*/ /*ERROR:Return value of function never checked*/
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
}
