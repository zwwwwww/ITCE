/*
From:ITC
14
Object orientedness defects
14.1
Malloc on class
14.1.2
The space size is negative
*/

void malloc_on_class_002() {
	int* a;
	a = (int*)malloc(-100); /*Tool should detect this line as error*/ /*ERROR:Object orientedness error*/
	scanf("%d", a);
	printf("%d", *a);
	free(a);
}
