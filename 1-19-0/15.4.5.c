/*
From:ITC
15
Control flow defects
15.4
Switches
15.4.5
Missing Default Statement
*/

void switch_005()
{
    int a = 3;
    switch (a) {
    case 1:
        break;
    case 2:
        break;
    default: /*Tool should Not detect this line as error*/ /*ERROR:control flow error*/
        break;
        // should have a default
    }
}
