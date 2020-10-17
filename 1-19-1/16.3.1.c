/*
From:ITC
16
Macros defects
16.3
Controlling macro checking
16.3.1
Function-like macro should not be used
*/
#define CUBE (X) ((X) * (X) * (X)) // Noncompliant
void func(void) {
	int i = 2;
	int a = CUBE(++i); // Noncompliant. Expands to: int a = ((++i) * (++i) * (++i))
	// ...
}
