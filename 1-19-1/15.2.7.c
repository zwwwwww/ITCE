/*
From:ITC
15
Control flow defects
15.2
Undefined behavior
15.2.7
cast pointers into more strictly aligned pointer types
*/


void undefined_behavior_007(void) {
	char c = 'x';
	int* ip = (int*)&c; /* This can lose information */
	char* cp = (char*)ip;

	/* Will fail on some conforming implementations */
	assert(cp == &c);
}
