/*
From:ITC
bug: 1
Concurrency defects
1.5
Locked but never unlock
1.5.6
two threads created in else condition
*/
pthread_mutex_t lock_never_unlock_006_glb_mutex_1 = PTHREAD_MUTEX_INITIALIZER;
pthread_mutex_t lock_never_unlock_006_glb_mutex_2 = PTHREAD_MUTEX_INITIALIZER;
#define CREATE_THREAD 1

void *lock_never_unlock_006_tsk_001(void *input)
{
#if !defined(CHECKER_POLYSPACE)
	long ip;

	pthread_mutex_lock(&lock_never_unlock_006_glb_mutex_1);
	ip = (long)input;
	ip = ip * 10;
#if defined PRINT_DEBUG
	printf(" Task6_1 !Lock Never Unlock, thread # % ld !\n ", ip);
#endif /* defined(PRINT_DEBUG) */

	if (ip >= 0)
		pthread_mutex_unlock(&lock_never_unlock_006_glb_mutex_1); /*Tool should not detect this line as error*/ /* No ERROR:Lock Never Unlock */
#endif																											/* defined(CHECKER_POLYSPACE) */
	return NULL;
}

void *lock_never_unlock_006_tsk_002(void *input)
{
#if !defined(CHECKER_POLYSPACE)
	long ip;

	pthread_mutex_lock(&lock_never_unlock_006_glb_mutex_2);
	ip = (long)input;
	ip = ip * 20;

#if defined PRINT_DEBUG
	printf(" Task6_2 !Lock Never Unlock, thread # % ld !\n ", ip);
#endif /* defined(PRINT_DEBUG) */
	pthread_mutex_unlock(&lock_never_unlock_006_glb_mutex_2);
#endif /* defined(CHECKER_POLYSPACE) */
	return NULL;
}

void lock_never_unlock_006()
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
		pthread_create(&th1, NULL, lock_never_unlock_006_tsk_001, (void *)t1);
		pthread_create(&th2, NULL, lock_never_unlock_006_tsk_002, (void *)t2);
		sleep(1);
	}
#endif /* defined(CHECKER_POLYSPACE) */
}
