/*
From:ITC
10
Simple type defects
10.6
float
10.6.5
float to int 
*/
                                                                                                                
void func_005(float f_a) {
    int i_a;

    /* Undefined if the integral part of f_a cannot be represented. */
    i_a = f_a;/*Tool should detect this line as error*/ /*ERROR:Simple type error*/
}
void float_005() {
    float a;
    scanf("%f", &a);
    func_005(a);
}
