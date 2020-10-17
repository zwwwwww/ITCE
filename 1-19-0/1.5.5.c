/*
From:ITC
bug: 1
Concurrency defects
1.5
Locked but never unlock
1.5.5
thread in else condition unlock
*/
pthread_mutex_t lock_never_unlock_005_glb_mutex = PTHREAD_MUTEX_INITIALIZER;
int lock_never_unlock_005_glb_data = 0;

#define NO_THREAD 0
int thread_set = 1;

void *lock_never_unlock_005_tsk_001(void *pram)
{
#if !defined(CHECKER_POLYSPACE)
	pthread_mutex_lock(&lock_never_unlock_005_glb_mutex);
	lock_never_unlock_005_glb_data = (lock_never_unlock_005_glb_data % 100) + 5;
	pthread_mutex_unlock(&lock_never_unlock_005_glb_mutex); /*Tool should not detect this line as error*/ /* No ERROR:Lock Never Unlock */

	unsigned long ip = (unsigned long)pthread_self();
	printf(" Task5 !Lock Never Unlock, threadID # % lu !gbl5 = % d \n ", ip, lock_never_unlock_005_glb_data);
#endif /* defined(CHECKER_POLYSPACE) */
	return NULL;
}

void lock_never_unlock_005()
{
#if !defined(CHECKER_POLYSPACE)
	if (thread_set == NO_THREAD)
	{
		;
	}
	else
	{
		pthread_t tid1;
		pthread_mutex_init(&lock_never_unlock_005_glb_mutex, NULL);
		pthread_create(&tid1, NULL, lock_never_unlock_005_tsk_001, NULL);
		pthread_join(tid1, NULL);
		pthread_mutex_destroy(&lock_never_unlock_005_glb_mutex);
	}
#endif /* defined(CHECKER_POLYSPACE) */
}
