/*
From:ITC
15
Control flow defects
15.6
Loop and if bodies
15.6.5
Empty Do While Statement
*/
void loop_and_if_bodies_005() {
    int a;
    scanf("%d", &a);
    while (a > 1) {
        printf("%d", a);/*Tool Not should detect this line as error*/ /*ERROR:control flow error*/
        a--;
    }
}
