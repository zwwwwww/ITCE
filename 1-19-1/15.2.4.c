/*
From:ITC
15
Control flow defects
15.2
Undefined behavior
15.2.4
the storage of compound literals
*/

typedef struct int_struct {
	int x;
} int_struct;

#define MAX_INTS 10

int undefined_behavior_004(void) {
	size_t i;
	int_struct* ints[MAX_INTS];

	for (i = 0; i < MAX_INTS; i++) {
		ints[i] = &(int_struct) { i };
	}

	for (i = 0; i < MAX_INTS; i++) {
		printf("%d\n", ints[i]->x);
	}

	return 0;
}
