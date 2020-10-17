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
extern size_t popcount(uintmax_t); /* See INT35-C */
#define PRECISION(umax_value) popcount(umax_value) 

int float_006() {
    assert(PRECISION(LONG_MAX) <= DBL_MANT_DIG * log2(FLT_RADIX));
    long int big = 1234567890L;
    double approx = big;
    printf("%ld\n", (big - (long int)approx));/*Tool should Not detect this line as error*/ /*ERROR:Simple type error*/
    return 0;
}
