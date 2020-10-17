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
    int i;
    scanf("%d", &i);
    goto A; // /*Tool should detect this line as error*/ /*ERROR:Control flow error*/
  A:
    while (i!=0)
    {
        if (i>0)
        {
            continue; // Noncompliant
        }
        else
        {
            i++;
        }
    }
    return; // Noncompliant; this is a void method
}"
