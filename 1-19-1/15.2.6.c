/*
From:ITC
15
Control flow defects
15.2
Undefined behavior
15.2.6
Conversion of a pointer to an integer type produces a value outside the range that can be represented 
*/

void undefined_behavior_006() {
	char* ptr;
	/* ... */
	unsigned int number = (unsigned int)ptr;
	/* ... */
}
