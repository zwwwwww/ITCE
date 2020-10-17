/*
From:ITC
16
Macros defects
16.3
Controlling macro checking
16.3.2
#undef should be used with caution
*/
#ifndef MY_HDR
#define MY_HDR
#endif
//...
#undef MY_HDR    /* Noncompliant */
