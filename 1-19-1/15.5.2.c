/*
From:ITC
15
Control flow defects
15.5
Deep breaks
15.5.2
while loops should not have more than one breaks
*/
void deep_breaks_002(){
    int j = 1;
    while (j!=0) {
        if (j>0) {
            j--;
            break;      // Compliant
        }
        if (j<0) {
            break;      // Non-compliant - second jump from loop
        }                /*Tool should detect this line as error*/ /*ERROR:Control flow  error*/
    }
}
