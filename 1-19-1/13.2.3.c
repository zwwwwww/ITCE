/*
From:ITC
13
"API defects
"
13.2
Memset function
13.2.3
The replaced object is not defined
*/

void memset_function_003() {
	int a[5] = { 1,2,3,4,5 };
	int i;
	memset(b, 0, 5*sizeof(int));  /*Tool should detect this line as error*/ /*ERROR:API error*/
	for (i = 0; i < 5; i++) {
		printf("%d ", a[i]);
	}
}
