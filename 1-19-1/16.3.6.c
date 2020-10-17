/*
From:ITC
16
Macros defects
16.3
Controlling macro checking
16.3.6
defined cannot take expressions as arguments.
*/

#if defined ( X > Y )  // Noncompliant; expressions not allowed
