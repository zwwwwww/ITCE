/*
From:ITC
14
Object orientedness defects
14.1
Malloc on class
14.1.6
Size is uncertain
*/

void malloc_on_class_006() {
	int n=2;
	void* p = malloc(n * sizeof(int));  /*Tool should detect this line as error*/ /*ERROR:Object orientedness error*/
}
