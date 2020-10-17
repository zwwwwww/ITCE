/*
From:ITC
18
Linux Kernel dectects
18.2
double lock
18.2.5
*
*/


typedef struct raw_spinlock {
	int lock;
} raw_spinlock_t;

typedef struct spinlock {
	struct raw_spinlock rlock;
} spinlock_t;

struct inode {
	int tmp_id;
	spinlock_t i_lock;
	spinlock_t i_lock2;
};

void* vmalloc(size_t size) {
	printf("\n");
}

static inline void spin_lock(spinlock_t *lock) {
	printf("lock\n");
}

static inline void spin_unlock(spinlock_t *lock) {
	printf("unlock\n");
}

struct container_node {
	struct inode my_inode1; 
	spinlock_t i_lock; 
	spinlock_t i_lock2; 
};

struct top_container {
	struct container_node *c;
};

void foo(struct top_container *tc) {
	spin_lock(&tc->c->i_lock);
}

void bar(struct top_container *tc) {
	spin_lock(&tc->c->i_lock2);
}

void sys_test() {
	struct top_container *tc = vmalloc(sizeof(struct top_container));
	tc->c = vmalloc(sizeof(struct container_node));
	foo(tc);
	spin_lock(&tc->c->i_lock);
	spin_unlock(&tc->c->i_lock);

	spin_lock(&tc->c->i_lock2);
	bar(tc);
	spin_unlock(&tc->c->i_lock2);
}

int main() {
	//sys_test();
	return 0;
}
