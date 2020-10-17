/*
From:ITC
10
Simple type defects
10.6
float
10.6.3
this code may produce a domain error if x is negative
*/
void func_003(double x) {
    double result;

    if (isless(x, 0.0)) {
        /* Handle domain error */
    }

    result = sqrt(x);/*Tool should Not detect this line as error*/ /*ERROR:Simple type error*/
}
void float_003() {
    double x;
    printf("输入一个double类型的值：");
    scanf("%lf", &x);
    func_003(x);
}
