/*
From:ITC
15
Control flow defects
15.4
Switches
15.4.1
Unnecessary Default Statement
*/
typedef enum {
    value1 = 0,
    value2 = 1
} eValues;

void switch_001()
{
    eValues a;
    switch (a)
    {
    case value1:
        break;
    case value2:
        break;
    default:          // this break is obsolete because all  /*Tool should detect this line as error*/ /*ERROR:control flow error*/
        break;        // values of variable a are already covered.
    }
}
