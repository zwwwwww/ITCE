/*
From:ITC
14
Object orientedness defects
14.1
Malloc on class
14.1.1
Insufficient space allocated
*/

void malloc_on_class_001() {
	char* str;
	str = (char*)malloc(1); /*Tool should detect this line as error*/ /*ERROR:Object orientedness error*/
	str = "hello";
	printf("string is %s", str);
	free(str);
}
