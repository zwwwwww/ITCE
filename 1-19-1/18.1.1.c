/*
From:ITC
18
Linux Kernel dectects
18.1
double free
18.1.1
*
*/


// should be replaced
void* vmalloc() {
	printf(""do something\n"");
	return malloc(42);
}

// should be replaced
void kfree(void *cmd) {
	printf(""do something %p\n"", cmd);
}

void sys_test() {
	int *p = (int*)vmalloc();

	kfree(p);
	kfree(p);
}

int main() {
	sys_test();
	return 0;
}
