/*
From:ITC
15
Control flow defects
15.10
goto
15.10.3
goto should jump to labels declared later in the same function
*/
int goto_003() {
    int j = 0;
L1:
    ++j;
    if (10 == j) {
        goto L2;         // forward jump ignored
    }
    // ...
    goto L1;           //  /*Tool should detect this line as error*/ /*ERROR:Control flow error*/
L2:
    return ++j;
}"
