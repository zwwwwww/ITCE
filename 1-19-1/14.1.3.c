/*
From:ITC
14
Object orientedness defects
14.1
Malloc on class
14.1.3
 The space size is decimal
*/

void malloc_on_class_003() {
	int* a;
	a = (int*)malloc(5.5); /*Tool should detect this line as error*/ /*ERROR:Object orientedness error*/
	scanf("%d", a);
	printf("%d", *a);
	free(a);
}
