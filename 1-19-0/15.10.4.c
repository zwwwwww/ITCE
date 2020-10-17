/*
From:ITC
15
Control flow defects
15.10
goto
15.10.4
jump statement should not be redundant
*/
void goto_004()
{
    int i = 0;
    while (i<10)
    {
        if (i<10)
        {
            i++;/*Tool should detect this line as error*/ /*ERROR:Control flow error*/
        }
    }
}
