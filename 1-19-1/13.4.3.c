/*
From:ITC
13
"API defects
"
13.4
Wrong call
13.4.3
The called function does not exist
*/
void wrong_call_003() {
	int x = 2;
	int y = 3;
	f(x, y);/*Tool should detect this line as error*/ /*ERROR:API error*/
}
