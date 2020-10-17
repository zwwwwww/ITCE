/*
From:ITC
14
Object orientedness defects
14.7
Initialization
14.7.2
a pointer to an object with automatic storage duration is returned from a function
*/

char* init_array(char* array, size_t len) {
	/* Initialize array */
	return ;
}
void initialization_002() {
	char* array[10];
	init_array(array, sizeof(array));/*Tool should Not detect this line as error*/ /*ERROR:Macros error*/
}
