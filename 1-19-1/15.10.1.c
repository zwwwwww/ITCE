/*
From:ITC
15
Control flow defects
15.10
goto
15.10.1
goto statements should not be used to jump into blocks
*/
void goto_001() {
    int a;
    scanf("%d", &a);
    if (a <= 0) {
        goto L2;  // Noncompliant; jumps into a different block   /*Tool should detect this line as error*/ /*ERROR:Control flow error*/
    }

    if (a == 0) {
        {
            goto L1; // Compliant
        }
        goto L2;  // Noncompliant; jumps into a block  /*Tool should detect this line as error*/ /*ERROR:Control flow error*/

    L1:
        for (int i = 0; i < a; i++) {
        L2:
            printf("%d ", i); //...  Should only have come here with a >=0. Loop is infinite if a < 0
        }
    }
}"
