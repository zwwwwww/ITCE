/*
From:ITC
bug: 1
Concurrency defects
1.8
Unlock without lock
        1.8.4
inside while loop and if condition
*/
pthread_mutex_t unlock_without_lock_004_glb_mutex_1 = PTHREAD_MUTEX_INITIALIZER;
pthread_mutex_t unlock_without_lock_004_glb_mutex_2 = PTHREAD_MUTEX_INITIALIZER;
int lock_never_unlock_004_glb_var = 0;
void *unlock_without_lock_004_tsk_001(void *input)
{
#if !defined(CHECKER_POLYSPACE)
	long ip;
	int i = 5;
	ip = (long)input;
	ip = ip * 10;
	while (i > 0)
	{
		if (ip >= 0)
		{
			pthread_mutex_lock(&unlock_without_lock_004_glb_mutex_1);

#if defined PRINT_DEBUG
			printf(" Task4_1 !Unlock without Lock, thread # % ld !\n ", ip);
#endif /* defined(PRINT_DEBUG) */
			lock_never_unlock_004_glb_var += 20;
			pthread_mutex_unlock(&unlock_without_lock_004_glb_mutex_1);
		}
		i--;
	}
#endif /* defined(CHECKER_POLYSPACE) */
	return NULL;
}

void *unlock_without_lock_004_tsk_002(void *input)
{
#if !defined(CHECKER_POLYSPACE)
	long ip;
	int i = 5;
	ip = (long)input;
	ip = ip * 20;
	while (i > 0)
	{
		if (ip >= 0)
		{
			if (i != 1)
				pthread_mutex_lock(&unlock_without_lock_004_glb_mutex_2); /*Tool should detect this line as error*/ /* ERROR:UnLock without lock */
			lock_never_unlock_004_glb_var += 5;
			pthread_mutex_unlock(&unlock_without_lock_004_glb_mutex_2);
		}
		i--;
	}
#if defined PRINT_DEBUG
	printf(" Task4_2 !Unlock without Lock, thread # % ld !\n ", ip);
#endif /* defined(PRINT_DEBUG) */
#endif /* defined(CHECKER_POLYSPACE) */
	return NULL;
}
void unlock_without_lock_004()
{
#if !defined(CHECKER_POLYSPACE)
	pthread_t th1, th2;
	intptr_t t1 = 10;
	intptr_t t2 = 20;
	pthread_create(&th1, NULL, unlock_without_lock_004_tsk_001, (void *)t1);
	pthread_create(&th2, NULL, unlock_without_lock_004_tsk_002, (void *)t2);
	sleep(1);
#endif /* defined(CHECKER_POLYSPACE) */
}
