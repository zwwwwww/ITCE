/*
From:ITC
13
"API defects
"
13.2
Memset function
13.2.7
The parameters do not meet the requirements
*/

void memset_function_007() {
	int a[5] = { 1,2,3,4,5 };
	int i;
	memset(a,0,sizeof(int) * 5);
	for (i = 0; i < 5; i++) {
		printf("%d ", a[i]); /*Tool should Not detect this line as error*/ /*ERROR:API error*/
	}
}
