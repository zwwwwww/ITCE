/*
From:ITC
15
Control flow defects
15.6
Loop and if bodies
15.6.1
 Empty Do While Statement
*/
void loop_and_if_bodies_001()
{
    int i = 0;
    do
    {     
        i++;// empty do-while statement
    } while (i<100);/*Tool should Not detect this line as error*/ /*ERROR:control flow error*/
}
