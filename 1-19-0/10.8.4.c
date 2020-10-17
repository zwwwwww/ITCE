/*
From:ITC
10
Simple type defects
10.8
sign
10.8.4
division between two signed int
*/

void func_004(signed long s_a, signed long s_b) {
    signed long result;
    if ((s_b == 0) || ((s_a == LONG_MIN) && (s_b == -1))) {
        /* Handle error */
    }
    else {
        result = s_a / s_b;/*Tool should Not detect this line as error*/ /*ERROR:Simple type error*/
    }
    /* ... */
}
void sign_004() {
    signed long a;
    signed long b;
    ptintf(""输入长整型符号整数："");
    scanf(""%d %d"", &a, &b);
    func_004(a, b);
}
