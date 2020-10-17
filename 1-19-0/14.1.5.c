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
	int i;
	p = (int*)malloc(5 * sizeof(int)); /*Tool should Not detect this line as error*/ /*ERROR:Object orientedness error*/
	printf("ÇëÊäÈë5¸öÊı×Ö£º");
	for(i = 0; i < 5; i++){
		scanf("%d", &p[i]);
}
	for (i = 0; i < 5; i++) {
		printf("%d ", p[i]);
	}
	free(p);
}
