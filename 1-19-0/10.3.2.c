/*
From:ITC
10
Simple type defects
10.3
shift
10.3.2
"Left Shift, signed Type"
*/
extern size_t popcount(uintmax_t);
#define PRECISION(x) popcount(x)

void func_002(signed long si_a, signed long si_b) {
    signed long result;
    if ((si_a < 0) || (si_b < 0) ||
        (si_b >= PRECISION(ULONG_MAX)) ||
        (si_a > (LONG_MAX >> si_b))) {   /*Tool should Not detect this line as error*/ /*ERROR:Simple type error*/
        /* Handle error */
    }
    else {
        result = si_a << si_b;
    }
    /* ... */
}
void shift_002() {
    signed long a;
    signed long b;
    printf(""输入符号整型和左移量:"");
    scanf(""%d %d"", &a, &b);
    func_002(a, b);
}
