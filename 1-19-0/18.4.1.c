/*
From:ITC
18
Linux Kernel dectects
18.4
use after free
18.4.1
*
*/


// should be replaced
void* vmalloc() {
	printf("do something\n");
	return malloc(42);
}

// should be replaced
void kfree(void *cmd) {
	printf("do something %p\n", cmd);
}

void sys_test() {
	int *p = (int*)vmalloc();
	int q;

	kfree(p);
	*p = q;
}

int main() {
	//sys_test();
	return 0;
}
