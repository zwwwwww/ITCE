/*
From:ITC
bug: 1
Concurrency defects
1.5
Locked but never unlock
1.5.1
one thread one function
*/
#if defined(CHECKER_POLYSPACE)
#define NULL ((void *)0)
int rand(void);
#endif
pthread_mutex_t lock_never_unlock_001_glb_mutex = PTHREAD_MUTEX_INITIALIZER;
#if defined(CHECKER_POLYSPACE)
void lock_never_unlock_001_glb_mutex_lock()
{
}
void lock_never_unlock_001_glb_mutex_unlock() {}
#endif /* #if defined(CHECKER_POLYSPACE) */
#ifndef __NO_POLYSPACE__
int lock_never_unlock_001_glb_data = 0;
void *lock_never_unlock_001_tsk_001(void *pram)
{
#if !defined(CHECKER_POLYSPACE)
	pthread_mutex_lock(&lock_never_unlock_001_glb_mutex);
	lock_never_unlock_001_glb_data = (lock_never_unlock_001_glb_data % 100) + 1;

	unsigned long ip = (unsigned long)pthread_self();
	printf(" Task1 !Lock Never Unlock, threadID # % lu !gbl1 = % d \n ", ip, lock_never_unlock_001_glb_data);
	/*Tool should detect this line as error*/ /* ERROR:Lock Never Unlock */
#endif										  /* defined(CHECKER_POLYSPACE) */
	return NULL;
}

void lock_never_unlock_001()
{
#if !defined(CHECKER_POLYSPACE)
	pthread_t tid1;
	pthread_mutex_init(&lock_never_unlock_001_glb_mutex, NULL);
	pthread_create(&tid1, NULL, lock_never_unlock_001_tsk_001, NULL);
	pthread_join(tid1, NULL);
	pthread_mutex_destroy(&lock_never_unlock_001_glb_mutex);
#endif /* defined(CHECKER_POLYSPACE) */
}
void lock_never_unlock_001_tskentry_001()
{
	while (1)
	{
		if (rand())
		{
			lock_never_unlock_001_tsk_001(NULL);
		}
	}
}
#endif /* defined(CHECKER_POLYSPACE) */
