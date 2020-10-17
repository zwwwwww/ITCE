/*
From:ITC
bug: 1
Concurrency defects
1.8
Unlock without lock
1.8.7
inside while loop and if condition
*/
pthread_mutex_t unlock_without_lock_007_glb_mutex_1 = PTHREAD_MUTEX_INITIALIZER;
pthread_mutex_t unlock_without_lock_007_glb_mutex_2 = PTHREAD_MUTEX_INITIALIZER;
int unlock_without_lock_007_glb_var = 0;
void *unlock_without_lock_007_tsk_001(void *input)
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
			pthread_mutex_lock(&unlock_without_lock_007_glb_mutex_1);
			unlock_without_lock_007_glb_var += 10;
			pthread_mutex_unlock(&unlock_without_lock_007_glb_mutex_1);
		}
		i--;
	}
#if defined PRINT_DEBUG
	printf("Task7_1! Unlock without Lock, thread #%ld!\n", ip);
#endif /* defined(PRINT_DEBUG) */
#endif /* defined(CHECKER_POLYSPACE) */
	return NULL;
}

void *unlock_without_lock_007_tsk_002(void *input)
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
			pthread_mutex_lock(&unlock_without_lock_007_glb_mutex_2);

			/* if(i!=5) */
			{
				unlock_without_lock_007_glb_var += 20;
				pthread_mutex_unlock(&unlock_without_lock_007_glb_mutex_2); /*Tool should not detect this line as error*/ /* No ERROR:UnLock without lock */
			}
		}
		i--;
	}
#if defined PRINT_DEBUG
	printf("Task7_2! Unlock without Lock, thread #%ld!\n", ip);
#endif /* defined(PRINT_DEBUG) */
#endif /* defined(CHECKER_POLYSPACE) */
	return NULL;
}

void unlock_without_lock_007()
{
#if !defined(CHECKER_POLYSPACE)
	pthread_t th1, th2;
	long int t1 = 10;
	long int t2 = 20;
	pthread_create(&th1, NULL, unlock_without_lock_007_tsk_001, (void *)t1);
	pthread_create(&th2, NULL, unlock_without_lock_007_tsk_002, (void *)t2);
	pthread_join(th1, NULL);
	pthread_join(th2, NULL);
#endif /* defined(CHECKER_POLYSPACE) */
}
