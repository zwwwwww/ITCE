/*
From:ITC
bug: 1
Concurrency defects
1.5
Locked but never unlock
1.5.2
lock twice unlock once
*/
#if defined(CHECKER_POLYSPACE)
#define NULL ((void *)0)
int rand(void);
#endif pthread_mutex_t lock_never_unlock_002_glb_mutex = PTHREAD_MUTEX_INITIALIZER;
#if defined(CHECKER_POLYSPACE)
void lock_never_unlock_002_glb_mutex_lock()
{
}
void lock_never_unlock_002_glb_mutex_unlock() {}
#endif /* #if defined(CHECKER_POLYSPACE) */

int lock_never_unlock_002_glb_data = 0;
void *lock_never_unlock_002_tsk_001(void *pram)
{
#if !defined(CHECKER_POLYSPACE)
	pthread_mutex_lock(&lock_never_unlock_002_glb_mutex);
	lock_never_unlock_002_glb_data = (lock_never_unlock_002_glb_data % 100) + 1;
	pthread_mutex_unlock(&lock_never_unlock_002_glb_mutex); /*Tool should not detect this line as error*/ /* No ERROR:Lock Never Unlock */

	pthread_mutex_lock(&lock_never_unlock_002_glb_mutex);
	lock_never_unlock_002_glb_data = (lock_never_unlock_002_glb_data % 100) + 1;
#if defined PRINT_DEBUG
	unsigned long ip = (unsigned long)pthread_self();
	printf(" Task2 !Lock Never Unlock, threadID # % lu !gbl2 = % d \n ", ip, lock_never_unlock_002_glb_data);
#endif /* defined(PRINT_DEBUG) */
	pthread_mutex_unlock(&lock_never_unlock_002_glb_mutex);

#endif /* defined(CHECKER_POLYSPACE) */
	return NULL;
}
void lock_never_unlock_002()
{
#if !defined(CHECKER_POLYSPACE)
	pthread_t tid1, tid2;
	pthread_mutex_init(&lock_never_unlock_002_glb_mutex, NULL);
	pthread_create(&tid1, NULL, lock_never_unlock_002_tsk_001, NULL);
	pthread_create(&tid2, NULL, lock_never_unlock_002_tsk_001, NULL);
	pthread_join(tid1, NULL);
	pthread_join(tid2, NULL);

#endif /* defined(CHECKER_POLYSPACE) */
}
#if defined(CHECKER_POLYSPACE)
void lock_never_unlock_002_tskentry_001()
{
	while (1)
	{
		if (rand())
		{
			lock_never_unlock_002_tsk_001(NULL);
		}
	}
}
#endif /* defined(CHECKER_POLYSPACE) */ "
