/*
From:ITC
4
Misc defects
4.3
Uninitialized variable 
4.3.6
long variable initialized in a ternary conditional operator
*/

extern int sink;
void uninit_var_006()
{
    long a;
    int flag = 10;
    (flag == 10) ? (a = 1) : (a = 5); /*Tool should not detect this line as error*/ /*No ERROR:Uninitialized Variable*/
}
