/*
From:ITC
16
Macros defects
16.3
Controlling macro checking
16.3.11
Macros used in preprocessor directives should be defined before use
*/
#define x 10
#if x > 0
#endif

#if defined ( y ) && ( y > 0 )  /* more compact form, same result as before */
...
#endif

