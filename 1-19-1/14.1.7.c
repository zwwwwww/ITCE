/*
From:ITC
14
Object orientedness defects
14.1
Malloc on class
14.1.7
 Check for dubious malloc arguments involving sizeof
*/

void malloc_on_class_007() {
	long* p = malloc(sizeof(short));
}
