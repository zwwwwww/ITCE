/*
From:ITC
4
Misc defects
4.3
Uninitialized variable 
4.3.4
Double variable initialized based on constant
*/

extern int dsink;
static const int UNINIT_VAR_004_TRUE = 1; /* true */
static const int UNINIT_VAR_004_FALSE = 0;

/*false */
void uninit_var_004()
{
    float dvar, dvar1;
    if (UNINIT_VAR_004_TRUE)
        dvar = 10.0;
    else if (UNINIT_VAR_004_FALSE == 0)
        dvar1 = 25.8;
    else
        dvar = dvar1 = 2.2; /*Tool should not detect this line as error*/ /*No ERROR:Uninitialized Variable*/
    dsink = dvar;
}
