/*
From:ITC
16
Macros defects
16.3
Controlling macro checking
16.3.7
string literals should not be concatennated implicitly
*/
const char* v1 = "ab";
const char* v2 = "a\n"
                 "b\n";

