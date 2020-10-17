/*
From:ITC
18
Linux Kernel dectects
18.5
use after run
18.5.1
*
*/


int *global_p;
int *global_p2;

void foo() {
	global_p2 = global_p;
	global_p = NULL;
}

void foo2() {
	int local_x = 1;
	global_p = &local_x;
	foo();
}

void sys_test() {
	//foo2();
}

int main() {
	sys_test();
	return 0;
} 
