/*
From:ITC
18
Linux Kernel dectects
18.1
double free
18.1.1
*
*/

void * vmalloc(){
	printf("do something\n");
	return malloc(42);
}
void sys_test() {
	int *p = (int*)vmalloc();
	kfree(p);
}

int main() {
	sys_test();
	return 0;
}
