/*
From:ITC
15
Control flow defects
15.6
Loop and if bodies
15.6.4
Empty If Statement
*/
                                                                                     
void loop_and_if_bodies_004()
{
    int a;
    scanf("%d", &a);
    if (a == 1)                  // empty if statement
    {
        printf("true");/*Tool Not should detect this line as error*/ /*ERROR:control flow error*/
    }
}
