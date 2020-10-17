/*
From:ITC
13
"API defects
"
13.2
Memset function
13.2.2
Replace integer with float
*/

void memset_function_002() {
	int a[5];
	int i;
	memset(a, 0, 5 * sizeof(int));  /*Tool should Not detect this line as error*/ /*ERROR:API error*/
	for (i = 0; i < 5; i++) {
		printf("%c ", a[i]);
	}
}
