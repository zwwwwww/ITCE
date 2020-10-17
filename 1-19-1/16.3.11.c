/*
From:ITC
16
Macros defects
16.3
Controlling macro checking
16.3.11
Macros used in preprocessor directives should be defined before use
*/
#if x > 0  /* x assumed to be zero if not defined */
#include SOMETHING_IMPORTANT
#endif

#ifdef y  /* Okay; y is not evaluated */
#if y > 0 /* Okay; y must be defined to reach this point */
...
#endif
#endif
