/*
From:ITC
4
Misc defects
4.3
Uninitialized variable 
4.3.8
Static Int variable initialized by return value of function
*/

int uninit_var_008_func_001(int a)
{
    static int ret;
    ret -= a;
    return ret;
}

void uninit_var_008()
{
    int flag = 1;
    int data;
    while (uninit_var_008_func_001(flag) > 0)
    {
        data += flag; /*Tool should detect this line as error*/ /*ERROR:Uninitialized Variable*/
    }
}
