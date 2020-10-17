/*
From:ITC
10
Simple type defects
10.6
float
10.6.5
float to int 
*/
extern size_t popcount(uintmax_t); /* See INT35-C */
#define PRECISION(umax_value) popcount(umax_value)

void func_005(float f_a) {
    int i_a;

    if (isnan(f_a) ||
        PRECISION(INT_MAX) < log2f(fabsf(f_a)) ||
        (f_a != 0.0F && fabsf(f_a) < FLT_MIN)) {
        /* Handle error */
    }
    else {
        i_a = f_a;/*Tool should Not detect this line as error*/ /*ERROR:Simple type error*/
    }
}
void float_005() {
    float f;
    scanf("%f", &f);
    func_005(f);
}
