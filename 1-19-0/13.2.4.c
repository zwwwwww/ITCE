/*
From:ITC
13
"API defects
"
13.2
Memset function
13.2.4
 Ch is signed
*/

void memset_function_004() {
	char c[3] = { 'a','b','c' };
	int i;
	memset(c, '1', 3 * sizeof(char));  /*Tool should Not detect this line as error*/ /*ERROR:API error*/
	for (i = 0; i < 3; i++) {
		printf("%c ", c[i]);
	}
}
