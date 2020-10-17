/*
From:ITC
16
Macros defects
16.3
Controlling macro checking
16.3.2
#undef should be used with caution
*/
#define LEVEL(i) 
int const i = 1
LEVEL(Debug);
LEVEL(Warning);
LEVEL(Error);
#undef LEVEL

