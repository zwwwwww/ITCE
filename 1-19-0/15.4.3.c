/*
From:ITC
15
Control flow defects
15.4
Switches
15.4.3
Missing break in switch statement
*/

void switch_003()
{
    int a;
    scanf("%d ", &a);
    switch (a) {
    case 1:
        break;
    case 2:
        printf("%d", a); /*Tool should Not detect this line as error*/ /*ERROR:control flow error*/
        break;// do something
    default:
        break;
    }
}
