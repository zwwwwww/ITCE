/*
From:ITC
15
Control flow defects
15.4
Switches
15.4.6
too few branches in switch statement
*/
                                                                                                                                          
void switch_006()
{
    int a = 2;
    switch (a) {
    case 1:
        break;
    case 2:
        printf("%d ", a); /*Tool should Not detect this line as error*/ /*ERROR:control flow error*/
        break;
    default:
        break;
    } // Better to use an if statement and check if variable a equals 1.
}
