/*
From:ITC
16
Macros defects
16.3
Controlling macro checking
16.3.3
reserved identifiers and functions in the C standard library should not be defined and declared
*/
#ifndef _MY_FILE
#define _MY_FILE   // Noncompliant: starts with '_'

#define FIELD__VAL(field) #field // Noncompliant: contains ""__""

int free(void* pArg, int len) {  // Noncompliant: free is a standard function
	int __i; // Noncompliant: starts with ""__""
	//...
}
#endif
