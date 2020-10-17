/*
From:ITC
10
Simple type defects
10.6
float
10.6.2
a floating-point loop counter is incremented by an amount that is too small to change its value 
*/
                                                                                                                                                              
void float_002(void) {
    for (float x = 100000001.0f; x <= 100000010.0f; x += 1.0f) {/*Tool should detect this line as error*/ /*ERROR:Simple type error*/
        printf("%f", x);
        /* Loop may not terminate */
    }
}
