/*
From:ITC
10
Simple type defects
10.6
float
10.6.4
This code may produce a domain error if x is negative and y is not an integer value or if x is 0 and y is 0
*/
void func_004(double x, double y) {
    double result;

    if (((x == 0.0f) && islessequal(y, 0.0)) || isless(x, 0.0)) {
        /* Handle domain or pole error */
    }

    {
#pragma STDC FENV_ACCESS ON
        if (math_errhandling & MATH_ERREXCEPT) {
            feclearexcept(FE_ALL_EXCEPT);
        }
        errno = 0;

        result = pow(x, y);/*Tool should Not detect this line as error*/ /*ERROR:Simple type error*/

        if ((math_errhandling & MATH_ERRNO) && errno != 0) {
            /* Handle range error */
        }
        else if ((math_errhandling & MATH_ERREXCEPT) &&
            fetestexcept(FE_INVALID | FE_DIVBYZERO |
                FE_OVERFLOW | FE_UNDERFLOW) != 0) {
            /* Handle range error */
        }
    }

    /* Use result... */
}
void float_004() {
    double x, y;
    printf("输入两个double类型的值:");
    scanf("%lf %lf", &x, &y);
    func_004(x, y);
}
