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
    for (size_t count = 1; count <= 10; ++count) {/*Tool should Not detect this line as error*/ /*ERROR:Simple type error*/
        float x = count / 10.0f;
        /* Loop iterates exactly 10 times */
    }
}