/*
From:ITC
16
Macros defects
16.3
Controlling macro checking
16.3.5
"Macros should not be used as replacement to ""typdef"" and ""using"""
*/

#define UINT unsigned int  // Noncompliant
#define INT int  // Noncompliant
UINT uabs(INT i);
