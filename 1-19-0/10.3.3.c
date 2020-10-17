/*
From:ITC
10
Simple type defects
10.3
shift
10.3.3
Right Shift
*/
extern size_t popcount(uintmax_t);
#define PRECISION(x) popcount(x)

void func_003(unsigned int ui_a, unsigned int ui_b) {
    unsigned int uresult = 0;
    if (ui_b >= PRECISION(UINT_MAX)) {/*Tool should Not detect this line as error*/ /*ERROR:Simple type error*/
        /* Handle error */
    }
    else {
        uresult = ui_a >> ui_b;
    }
    /* ... */
}
void shift_003() {
    unsigned int a;
    unsigned int b;
    printf(""输入符号整型和右移量:"");
    scanf(""%d %d"", &a, &b);
    func_003(a, b);
}
