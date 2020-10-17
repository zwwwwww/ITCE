/*
From:ITC
18
Linux Kernel dectects
18.5
use after run
18.5.7
*
*/


int *global_p;

void foo(int *param) {
	int local_x = 1;
	param = &local_x;
}

void do_test() {
	int* local_p;
	foo(global_p);	
	global_p = local_p;
}

void sys_test() {
	do_test();
}

int main() {
	//sys_test();
	return 0;
} 
