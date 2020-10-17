/*
From:ITC
13
API defects
13.6
Use of Potentially Dangerous Function
13.6.1
create a local copy of a buffer to perform some manipulations to the data.
*/
void dangerous_001(char* string) {
	char buf[24];
	strcpy(buf, string);/*Tool should detect this line as error*/ /*ERROR: dangerous function error*/
}
