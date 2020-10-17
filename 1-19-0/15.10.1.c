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
    scanf("%d ", &a);
    if (a <= 0) {
        a++;
    }

    if (a == 0) {
        {
            goto L1; //  /*Tool should detect this line as error*/ /*ERROR:Control flow error*/
        }

    L1:
        for (int i = 0; i < a; i++) {
        L2:
            printf("%d", i);
        }
    }
}"
