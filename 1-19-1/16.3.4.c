/*
From:ITC
16
Macros defects
16.3
Controlling macro checking
16.3.4
key words shall not be used as macros identifiers
*/

#define int some_other_type // Noncompliant
#include <stdlib.h>;
