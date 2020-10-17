/*
From:ITC
10
Simple type defects
10.8
sign
10.8.3
Multiplication between two signed int
*/
extern size_t popcount(uintmax_t);
#define PRECISION(umax_value) popcount(umax_value) 

void func_003(signed int si_a, signed int si_b) {
    signed int result;
    signed long long tmp;
    assert(PRECISION(ULLONG_MAX) >= 2 * PRECISION(UINT_MAX));
    tmp = (signed long long)si_a * (signed long long)si_b;/*Tool should Not detect this line as error*/ /*ERROR:Simple type error*/
     /*
     * If the product cannot be represented as a 32-bit integer,
     * handle as an error condition.
     */
    if ((tmp > INT_MAX) || (tmp < INT_MIN)) {
        /* Handle error */
    }
    else {
        result = (int)tmp;
    }
    /* ... */
}
void sign_003() {
    signed int a;
    signed int b;
    ptintf(""ÊäÈë·ûºÅÕûÊý£º"");
    scanf(""%d %d"", &a, &b);
    func_003(a,b);
}
