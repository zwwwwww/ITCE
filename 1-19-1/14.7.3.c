/*
From:ITC
14
Object orientedness defects
14.7
Initialization
14.7.3
 Output Parameter
*/

void squirrel_away(char** ptr_param) {
	char local[10];
	/* Initialize array */
	*ptr_param = local;
}
void initialization_003() {
	char* ptr;
	squirrel_away(&ptr);/*Tool should detect this line as error*/ /*ERROR:initialization error*/
	/* ptr is live but invalid here */
}
