/*
From:ITC
13
"API defects
"
13.2
Memset function
13.2.5
parameter order is wrong
*/

void memset_function_005() {
	int a[5] = { 1,2,3,4,5 };
	int i;
	memset(a, 5 * sizeof(int), 0); /*Tool should detect this line as error*/ /*ERROR:API error*/
	for (i = 0; i < 3; i++) {
		printf("%d ", a[i]);
	}
}
