/*
From:ITC
10
Simple type defects
10.8
sign
10.8.6
Unary Negation a signed int
*/
void func_006(signed long s_a) {
    signed long result;
    if (s_a == LONG_MIN) {
        /* Handle error */
    }
    else {
        result = -s_a;/*Tool should Not detect this line as error*/ /*ERROR:Simple type error*/
    }
    /* ... */
}
void sign_006() {
    signed long a;
    ptintf(""ÊäÈë·ûºÅÕûÊý£º"");
    scanf(""%d"", &a);
    func_006(a);
}
