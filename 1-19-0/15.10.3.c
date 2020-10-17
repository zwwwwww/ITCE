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
    int j;
    for (j = 0; j < 11; j++) {
        printf("%d ", j);
    }
    return ++j;/*Tool should detect this line as error*/ /*ERROR:Control flow error*/
}"
