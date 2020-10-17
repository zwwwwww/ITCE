/*
From:ITC
14
Object orientedness defects
14.1
Malloc on class
14.1.5
Size does not meet the allocation requirements
*/

void malloc_on_class_005() {
	int* p;
	p = (int*)malloc(0.5 * sizeof(int)); /*Tool should detect this line as error*/ /*ERROR:Object orientedness error*/
	scanf("%d", p);
	printf("p=%d", *p);
	free(p);
}
