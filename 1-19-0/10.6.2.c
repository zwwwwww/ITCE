/*
From:ITC
10
Simple type defects
10.6
float
10.6.2
a floating-point loop counter is incremented by an amount that is too small to change its value 
*/
                                                                                                                                                                    
void float_002() {
    for (size_t count = 1; count <= 10; ++count) {/*Tool should Not detect this line as error*/ /*ERROR:Simple type error*/
        float x = 100000000.0f + (count * 1.0f);
        /* Loop iterates exactly 10 times */
    }
}