/*
From:ITC
14
Object orientedness defects
14.7
Initialization
14.7.9
declarations should not be empty
*/

void initialization_009() {
	int;/*Tool should detect this line as error*/ /*ERROR:initialization error*/
}
