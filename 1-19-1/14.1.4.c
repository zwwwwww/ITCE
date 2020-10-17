/*
From:ITC
14
Object orientedness defects
14.1
Malloc on class
14.1.4
Malloc allocation space not cast
*/

void malloc_on_class_004() {
	int* i;
	i =(void*) malloc(sizeof(int));/*Tool should detect this line as error*/ /*ERROR:Object orientedness error*/
	scanf("%d", i);
	printf("%d", *i);
	free(i);
}
