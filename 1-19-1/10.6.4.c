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
    result = pow(x, y);/*Tool should detect this line as error*/ /*ERROR:Simple type error*/
}
void float_004() {
    double x, y;
    printf("��������double���͵�ֵ;");
    scanf("%lf %lf", &x, &y);
    func_004(x, y);
}
