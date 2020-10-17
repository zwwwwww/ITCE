/*
From:ITC
15
Control flow defects
15.6
Loop and if bodies
15.6.2
Empty else block
*/
                                                
int loop_and_if_bodies_002()
{
    int a;
    scanf("%d", &a);
    if (a>0)
    {
        return a + 1;
    }
    else                // empty else statement, can be safely removed
    {
        return a;/*Tool Not should detect this line as error*/ /*ERROR:control flow error*/
    }
}
