/*
From:ITC
15
Control flow defects
15.10
goto
15.10.2
goto statements should not be used
*/
void goto_002(){
        int i = 0;
    loop:
        printf("i = %d\n", i);
        i++;
        if (i < 10) {
            goto loop;   /*Tool should detect this line as error*/ /*ERROR:Control flow error*/
        }
}"
