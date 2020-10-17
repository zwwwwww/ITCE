/*
From:ITC
14
Object orientedness defects
14.7
Initialization
14.7.2
a pointer to an object with automatic storage duration is returned from a function
*/

char* init_array(void) {
	char array[10];/* Initialize array */
	return array;
}
void initialization_002() {
	init_array();/*Tool should detect this line as error*/ /*ERROR:initialization error*/
}
