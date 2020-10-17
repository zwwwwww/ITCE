/*
From:ITC
18
Linux Kernel dectects
18.4
use after free
18.4.2
*
*/


struct request {
	char *cmd;
};

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
	char *c = (char*)vmalloc();
	struct request rq;
	char p;

	rq.cmd = c;

	if(c)
		kfree(c);

	if(rq.cmd)
		*rq.cmd = p;
}

int main() {
	//sys_test();
	return 0;
}
