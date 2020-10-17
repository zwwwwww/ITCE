/*
From:ITC
13
API defects
13.6
Use of Potentially Dangerous Function
13.6.2
It is possible to exceed the array size
*/
void dangerous_002(int n) {
	int i;
	int a[10];
	for (i = 0; i < n; i++) {
		scanf("%d", &a[i]);/*Tool should detect this line as error*/ /*ERROR: dangerous function error*/
	}
}
