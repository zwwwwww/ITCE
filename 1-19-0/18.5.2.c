/*
From:ITC
18
Linux Kernel dectects
18.5
use after run
18.5.2
*
*/


void foo(int **param) {
	int local_x = 1;
	*param = &local_x;
}

int* init() {
	int *p;
	p = (int*)malloc(sizeof(int));
	return p;
}

void sys_test() {
	int* local_p = init();
	foo(&local_p);	
}

int main() {
	//sys_test();
	return 0;
} 
