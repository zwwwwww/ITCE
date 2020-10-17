/*
From:ITC
18
Linux Kernel dectects
18.5
use after run
18.5.4
*
*/


struct vec2D {
	int x;
	int *y;
};

int *global_p;

void foo(struct vec2D *param_v) {
	int *local_x;
	struct vec2D local_v2;
	local_v2.y = &param_v->x;
	global_p = local_v2.y;
}

void bar() {
	struct vec2D local_v;
	foo(&local_v);
}

void sys_test() {
	bar();
}

int main() {
	sys_test();
	return 0;
} 
