/*
From:ITC
16
Macros defects
16.3
Controlling macro checking
16.3.3
reserved identifiers and functions in the C standard library should not be defined and declared
*/
#ifndef MY_FILE
#define MY_FILE

#define FIELD_VAL(field) #field

int clean(void* pArg, int len) {
	int i;
	//...
}
#endif
