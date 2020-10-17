/*
From:ITC
10
Simple type defects
10.6
float
10.6.6
" a large value of type long int is converted to a value of type float 
   without ensuring it is representable in the type"
*/
                                                                                                      
int float_006(void) {
    long int big = 1234567890L;
    float approx = big;/*Tool should detect this line as error*/ /*ERROR:Simple type error*/
    printf("%ld\n", (big - (long int)approx));
    return 0;
}
