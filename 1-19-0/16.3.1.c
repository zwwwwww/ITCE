/*
From:ITC
16
Macros defects
16.3
Controlling macro checking
16.3.1
Function-like macro should not be used
*/
inline int cube(int i) {
	return i * i * i;
}

void controllling_macro_checking_001(void) {
	int i = 2;
	int a = cube(++i); // yields 27
	// ...
}
