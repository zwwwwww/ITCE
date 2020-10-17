/*
From:ITC
18
Linux Kernel dectects
18.1
double free
18.1.9
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
	struct request *rq = (struct request*)vmalloc();
	unsigned int cond;

	while(cond) {
		if(rq) {
			kfree(rq);
			rq = NULL;
			break;
		}
		cond--;
	}

	//if(rq)
	//	kfree(rq);
}

int main() {
	sys_test();
	return 0;
}
