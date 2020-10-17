/*
From:ITC
14
Object orientedness defects
14.7
Initialization
14.7.3
 Output Parameter
*/

char local[10];
void squirrel_away(char** ptr_param) {
	
	/* Initialize array */
	*ptr_param = local;
}
void initialization_003() {
	char* ptr;
	squirrel_away(&ptr);/*Tool should Not detect this line as error*/ /*ERROR:Macros error*/
	/* ptr is live but invalid here */
}
