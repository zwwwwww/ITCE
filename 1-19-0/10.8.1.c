/*
From:ITC
10
Simple type defects
10.8
sign
10.8.1
addition between two signed int
*/
void func_001(signed int si_a, signed int si_b) {
    signed int sum;
    if (((si_b > 0) && (si_a > (INT_MAX - si_b))) ||
        ((si_b < 0) && (si_a < (INT_MIN - si_b)))) {
        /* Handle error */
    }
    else {
        sum = si_a + si_b;/*Tool should Not detect this line as error*/ /*ERROR:Simple type error*/
    }
    /* ... */
}
void sign_001() {
    signed int a;
    signed int b;
    ptintf("ÊäÈë·ûºÅÕûÊý£º");
    scanf("%d %d", &a, &b);
    func_001(a,b);
}
