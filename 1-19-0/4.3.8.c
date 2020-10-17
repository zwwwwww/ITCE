/*
From:ITC
4
Misc defects
4.3
Uninitialized variable 
4.3.8
Static Int variable initialized by return value of function
*/

extern int sink;
int uninit_var_008_func_001(int a)
{
    static int ret = 10;
    ret -= a;
    return ret;
}

void uninit_var_008()
{
    static int flag = 1;
    static int data;
    while (uninit_var_008_func_001(flag) > 0)
    {
        data += flag; /*Tool should not detect this line as error*/ /*No ERROR:Uninitialized Variable*/
    }
}
