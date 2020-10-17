/*
From:ITC
bug: 1
Concurrency defects
1.5
Locked but never unlock
1.5.8
2 threads created in else condition
*/
pthread_mutex_t lock_never_unlock_008_glb_mutex_1 = PTHREAD_MUTEX_INITIALIZER;
pthread_mutex_t lock_never_unlock_008_glb_mutex_2 = PTHREAD_MUTEX_INITIALIZER;
#define CREATE_THREAD 1
typedef struct
{
	int a;
	int b;
} lock_never_unlock_008_s_001;
lock_never_unlock_008_s_001 lock_never_unlock_008_glb_sptr = {0};
void *lock_never_unlock_008_tsk_001(void *input)
{
#if !defined(CHECKER_POLYSPACE)
	long ip;
	int i;
	ip = (long)input;
	ip = ip * 10;
	for (i = 0; i <= 4; i++)
	{
		if (ip >= 0)
		{
			pthread_mutex_lock(&lock_never_unlock_008_glb_mutex_1);
			lock_never_unlock_008_glb_sptr.a += 10;
			if (i != 5)
				pthread_mutex_unlock(&lock_never_unlock_008_glb_mutex_1); /*Tool should not detect this line as error*/ /* No ERROR:Lock Never Unlock */
		}
	}
#if defined PRINT_DEBUG
	printf(" Task8_1 !Lock But Never Unlock, thread # % ld !aa = % d\n ", ip, lock_never_unlock_008_glb_sptr.a);
#endif /* defined(PRINT_DEBUG) */
#endif /* defined(CHECKER_POLYSPACE) */
	return NULL;
}

void *lock_never_unlock_008_tsk_002(void *input)
{
#if !defined(CHECKER_POLYSPACE)
	long ip;
	int i;
	ip = (long)input;
	ip = ip * 20;
	for (i = 0; i <= 4; i++)
	{
		if (ip >= 0)
		{
			pthread_mutex_lock(&lock_never_unlock_008_glb_mutex_2);
			lock_never_unlock_008_glb_sptr.a += 20;
			pthread_mutex_unlock(&lock_never_unlock_008_glb_mutex_2);
		}
	}
#if defined PRINT_DEBUG
	printf(" Task8_2 !Lock But Never Unlock, thread # % ld !aa = % d\n ", ip, lock_never_unlock_008_glb_sptr.a);
#endif /* defined(PRINT_DEBUG) */

#endif /* defined(CHECKER_POLYSPACE) */
	return NULL;
}

void lock_never_unlock_008()
{
	int thread_set = 0;
#if !defined(CHECKER_POLYSPACE)
	pthread_t th1, th2;
	intptr_t t1 = 10;
	intptr_t t2 = 20;
	if (thread_set == CREATE_THREAD)
	{
		;
	}
	else
	{
		pthread_create(&th1, NULL, lock_never_unlock_008_tsk_001, (void *)t1);
		pthread_create(&th2, NULL, lock_never_unlock_008_tsk_002, (void *)t2);
		sleep(1);
	}

#endif /* defined(CHECKER_POLYSPACE) */
}
