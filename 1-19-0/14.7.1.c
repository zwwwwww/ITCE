/*
From:ITC
14
Object orientedness defects
14.7
Initialization
14.7.1
Differing Storage Durations
*/

void initialization_001() {
	const char c_str[] = "Everything OK";
	const char* p = c_str;/*Tool should Not detect this line as error*/ /*ERROR:Macros error*/
	/* ... */
}
