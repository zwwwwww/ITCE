/*
From:ITC
10
Simple type defects
10.6
float
10.6.1
a floating-point variable is used as a loop counter
*/
                                                                                                                                       
void float_001() {
    for (float x = 0.1f; x <= 1.0f; x += 0.1f) {/*Tool should detect this line as error*/ /*ERROR:Simple type error*/
        printf("%f", x);
        /* Loop may iterate 9 or 10 times */
    }
}
