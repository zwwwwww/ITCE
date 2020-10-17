/*
From:ITC
15
Control flow defects
15.5
Deep breaks
15.5.1
for loops should not have more than one breaks
*/
void deep_breaks_001() {
    for (int i = 0; i < 10; i++) {
        if (i < 3) {
            break;      //  Compliant
        }
        else if (i > 3 && i < 5) {
            break;      //  Non-compliant - second jump from loop
        }               /*Tool should detect this line as error*/ /*ERROR:Control flow error*/
        else {
            i++;
        }
    }
}
