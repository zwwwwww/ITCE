/*
From:ITC
13
"API defects
"
13.3
Obsolete function
13.3.1
increment should not be used  to set boolean variable to true
*/

void obsolete_function_001() {
	bool alive;
	alive = true;/*Tool should Not detect this line as error*/ /*ERROR:API error*/
}
