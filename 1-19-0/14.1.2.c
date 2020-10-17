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
	a = (int*)malloc(100); /*Tool should Not detect this line as error*/ /*ERROR:Object orientedness error*/
	*a = 10;
	printf("%d", *a);
	free(a);
}
