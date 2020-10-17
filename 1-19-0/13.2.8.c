/*
From:ITC
13
"API defects
"
13.2
Memset function
13.2.8
The parameters do not meet the requirements
*/

void memset_function_008() {
	int a[5];
	int i;
	memset(a,0,20);
	for (i = 0; i < 5; i++) {
		printf("%d ", a[i]); /*Tool should Not detect this line as error*/ /*ERROR:API error*/
	}

}
