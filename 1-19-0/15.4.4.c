/*
From:ITC
15
Control flow defects
15.4
Switches
15.4.4
label becomes part of the switch statement.
*/

void switch_004()
{
    int a = 3;
    switch (a) {
    case 1:
        break;
    case 2:     // label in a switch statement in really confusing
        break; /*Tool should Not detect this line as error*/ /*ERROR:control flow error*/
    default:
        break;
    }
}
