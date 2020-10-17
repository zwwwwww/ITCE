/*
From:ITC
15
Control flow defects
15.4
Switches
15.4.2
Misplace Default Label
*/

void switch_002()
{
    int a;
    scanf("%d ", &a);
    switch (a) {
    case 1:
        break;
    case 2:
        break;
    default:  // the default case should be last
        break; /*Tool should Not detect this line as error*/ /*ERROR:control flow error*/
    }
}
