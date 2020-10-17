/*
From:ITC
4
Misc defects
4.3
Uninitialized variable 
4.3.6
long variable initialized in a ternary conditional operator
*/

void uninit_var_006()
{
    long a;
    int flag = 0;
    (flag == 10) ? (a = 1) : (flag = a); /*Tool should detect this line as error*/ /*ERROR:Uninitialized Variable*/
}
