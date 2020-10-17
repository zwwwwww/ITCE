/*
From:ITC
15
Control flow defects
15.10
goto
15.10.2
goto statements should not be used
*/
void goto_002() {
    for (int i = 0; i < 10; i++) {
        printf("i = %d\n", i);/*Tool should detect this line as error*/ /*ERROR:Control flow error*/
    }
}
