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
    for (int i = 0; i < 10; ) {
        if (i < 3) {
            break;      //  Compliant
        }
        else if (i > 3 && i < 5) {
            i++;      
        }               /*Tool should Not detect this line as error*/ /*ERROR:Control error*/
        else {
            i=i+2;
        }
    }
}
