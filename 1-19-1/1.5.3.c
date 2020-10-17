/*
From:ITC
bug: 1
Concurrency defects
1.5
Locked but never unlock
1.5.3
multiple functions two threads
*/
#if defined(CHECKER_POLYSPACE)
#define NULL ((void *)0)
int rand(void);
#endif
pthread_mutex_t lock_never_unlock_003_glb_mutex = PTHREAD_MUTEX_INITIALIZER;
#if defined(CHECKER_POLYSPACE)
void lock_never_unlock_003_glb_mutex_lock()
{
}
void lock_never_unlock_003_glb_mutex_unlock() {}
#endif /* #if defined(CHECKER_POLYSPACE) */

float lock_never_unlock_003_glb_data = 1000.0;

void lock_never_unlock_003_func_001(void *pram)
{
#if !defined(CHECKER_POLYSPACE)
	pthread_mutex_lock(&lock_never_unlock_003_glb_mutex);
	lock_never_unlock_003_glb_data = (lock_never_unlock_003_glb_data) + 1.2;
	/*Tool should detect this line as error*/ /* ERROR:Lock Never Unlock */
#if defined PRINT_DEBUG
	int ip = (int)pram;
	printf(" Task3 !Lock Never Unlock, thread # % d !gbl3 = % f \n ", ip, lock_never_unlock_003_glb_data);
#endif /* defined(PRINT_DEBUG) */
#endif /* ! defined(CHECKER_POLYSPACE) */
}
void *lock_never_unlock_003_tsk_001(void *pram)
{
#if !defined(CHECKER_POLYSPACE)

	pthread_mutex_lock(&lock_never_unlock_003_glb_mutex);
	lock_never_unlock_003_glb_data = (lock_never_unlock_003_glb_data) + 3.5;
	lock_never_unlock_003_func_001(pram);
	pthread_mutex_unlock(&lock_never_unlock_003_glb_mutex);
#endif /* defined(CHECKER_POLYSPACE) */
	return NULL;
}

void lock_never_unlock_003()
{
#if !defined(CHECKER_POLYSPACE)
	pthread_t tid1, tid2;
	intptr_t t1 = 10, t2 = 20;
	pthread_mutex_init(&lock_never_unlock_003_glb_mutex, NULL);
	pthread_create(&tid1, NULL, lock_never_unlock_003_tsk_001, (void *)t1);
	pthread_create(&tid2, NULL, lock_never_unlock_003_tsk_001, (void *)t2);
	pthread_join(tid1, NULL);
	pthread_join(tid2, NULL);
	pthread_mutex_destroy(&lock_never_unlock_003_glb_mutex);
#endif /* defined(CHECKER_POLYSPACE) */
}
void lock_never_unlock_003_tskentry_001()
{
	while (1)
	{
		if (rand())
		{
			lock_never_unlock_003_tsk_001(NULL);
		}
	}
}
#endif /* defined(CHECKER_POLYSPACE) */
