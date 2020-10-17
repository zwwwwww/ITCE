/*
From:ITC
15
Control flow defects
15.5
Deep breaks
15.5.3
loops should not have more than one breaks
*/
                                                                                                         
void deep_breaks_003() {
    for (int i = 0; i < 10; i++) { // noncompliant, loop only executes once
        printf("i is %d", i);
        break;              /*Tool should detect this line as error*/ /*ERROR:Control flow error*/
    }
}
