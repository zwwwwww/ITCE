/*
From:ITC
18
Linux Kernel dectects
18.2
double lock
18.2.7
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

void add_dquot_ref(struct inode *inode) {
	spin_lock(&inode->i_lock);

	if(inode) 
		return;

	spin_unlock(&inode->i_lock);
}

void sys_test() {
	struct inode *inode_ptr;
	struct inode my_inode;
	inode_ptr = &my_inode;

	add_dquot_ref(inode_ptr);

	spin_unlock(&inode_ptr->i_lock);
	spin_lock(&inode_ptr->i_lock);
}

int main() {
	//sys_test();
	return 0;
}
