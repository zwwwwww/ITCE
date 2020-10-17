/*
From:ITC
bug: 1
Concurrency defects
1.5
Locked but never unlock
1.5.7
inside while loop and if condition
*/
pthread_mutex_t lock_never_unlock_007_glb_mutex_1 = PTHREAD_MUTEX_INITIALIZER;
pthread_mutex_t lock_never_unlock_007_glb_mutex_2 = PTHREAD_MUTEX_INITIALIZER;
int lock_never_unlock_007_glb_var = 0;
void *lock_never_unlock_007_tsk_001(void *input)
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
			pthread_mutex_lock(&lock_never_unlock_007_glb_mutex_1);
			lock_never_unlock_007_glb_var += 10;
			pthread_mutex_unlock(&lock_never_unlock_007_glb_mutex_1);
		}
		i--;
	}
#if defined PRINT_DEBUG
	printf(" Task7_1 !Lock Never Unlock, thread # % ld !\n ", ip);
#endif /* defined(PRINT_DEBUG) */
#endif /* defined(CHECKER_POLYSPACE) */
	return NULL;
}

void *lock_never_unlock_007_tsk_002(void *input)
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
			pthread_mutex_lock(&lock_never_unlock_007_glb_mutex_2);

			/* if(i!=5) */
			{
				lock_never_unlock_007_glb_var += 20;
				pthread_mutex_unlock(&lock_never_unlock_007_glb_mutex_2); /*Tool should not detect this line as error*/ /* No ERROR:Lock Never Unlock */
			}
		}
		i--;
	}
#if defined PRINT_DEBUG
	printf(" Task7_2 !Lock Never Unlock, thread # % ld !\n ", ip);
#endif /* defined(PRINT_DEBUG) */
#endif /* defined(CHECKER_POLYSPACE) */
	return NULL;
}

void lock_never_unlock_007()
{
#if !defined(CHECKER_POLYSPACE)
	pthread_t th1, th2;
	intptr_t t1 = 10;
	intptr_t t2 = 20;
	pthread_create(&th1, NULL, lock_never_unlock_007_tsk_001, (void *)t1);
	pthread_create(&th2, NULL, lock_never_unlock_007_tsk_002, (void *)t2);
	pthread_join(th1, NULL);
	pthread_join(th2, NULL);
#endif /* defined(CHECKER_POLYSPACE) */
}
