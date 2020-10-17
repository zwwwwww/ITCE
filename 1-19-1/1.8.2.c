/*
From:ITC
bug: 1
Concurrency defects
1.8
Unlock without lock
        1.8.2
two thread inside a if condition
*/
int rand(void);
pthread_mutex_t unlock_without_lock_002_glb_mutex = PTHREAD_MUTEX_INITIALIZER;
#if defined(CHECKER_POLYSPACE)
void unlock_without_lock_002_glb_mutex_lock()
{
}
void unlock_without_lock_002_glb_mutex_unlock() {}
#endif /* #if defined(CHECKER_POLYSPACE) */

unsigned long unlock_without_lock_002_glb_data = 0;
int const unlock_without_lock_002_var = 10;
void *unlock_without_lock_002_tsk_001(void *pram)
{
#if !defined(CHECKER_POLYSPACE)
	if (unlock_without_lock_002_var == (intptr_t)pram)
	{
		pthread_mutex_lock(&unlock_without_lock_002_glb_mutex);
		unlock_without_lock_002_glb_data = (unlock_without_lock_002_glb_data % 100) + 1;
		pthread_mutex_unlock(&unlock_without_lock_002_glb_mutex);
	}
	if (unlock_without_lock_002_var == (intptr_t)pram)
	{
		/*pthread_mutex_lock(&unlock_without_lock_002_glb_mutex);*/
		unlock_without_lock_002_glb_data = (unlock_without_lock_002_glb_data % 100) + 1;
#if defined PRINT_DEBUG
		unsigned long ip = (unsigned long)pthread_self();
		printf(" Task2 !Unlock without Lock, threadID # % lu !gbl2 = % lu \n ", ip, unlock_without_lock_002_glb_data);
#endif																										/* defined(PRINT_DEBUG) */
		pthread_mutex_unlock(&unlock_without_lock_002_glb_mutex); /*Tool should detect this line as error*/ /* ERROR:UnLock without lock */
	}
#endif /* defined(CHECKER_POLYSPACE) */
	return NULL;
}

void unlock_without_lock_002()
{
#if !defined(CHECKER_POLYSPACE)
	pthread_t tid1, tid2;
	intptr_t const unlock_without_lock_002_t1 = 10;
	intptr_t const unlock_without_lock_002_t2 = 20;
	pthread_mutex_init(&unlock_without_lock_002_glb_mutex, NULL);
	pthread_create(&tid1, NULL, unlock_without_lock_002_tsk_001, (void *)unlock_without_lock_002_t1);
	pthread_create(&tid2, NULL, unlock_without_lock_002_tsk_001, (void *)unlock_without_lock_002_t2);
	pthread_join(tid1, NULL);
	pthread_join(tid2, NULL);
#endif /* defined(CHECKER_POLYSPACE) */
}

#if defined(CHECKER_POLYSPACE)
void unlock_without_lock_002_tskentry_001()
{
	while (1)
	{
		if (rand())
		{
			unlock_without_lock_002_tsk_001(NULL);
		}
	}
}
#endif /* defined(CHECKER_POLYSPACE) */
