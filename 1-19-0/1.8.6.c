/*
From:ITC
bug: 1
Concurrency defects
1.8
Unlock without lock
1.8.6
multiple fnctions two threads in else condition
*/
pthread_mutex_t unlock_without_lock_006_glb_mutex_1 = PTHREAD_MUTEX_INITIALIZER;
pthread_mutex_t unlock_without_lock_006_glb_mutex_2 = PTHREAD_MUTEX_INITIALIZER;
#define CREATE_THREAD 1
char unlock_without_lock_006_glb_buf[5] = "BBBBB";
void *unlock_without_lock_006_tsk_001(void *input)
{
#if !defined(CHECKER_POLYSPACE)
	long ip;
	int i;
	ip = (long)input;
	ip = ip * 10;
	for (i = 0; i < 5; i++)
	{
		if (ip >= 0)
		{
			pthread_mutex_lock(&unlock_without_lock_006_glb_mutex_1); /*Tool should not detect this line as error*/ /* No ERROR:UnLock without lock */
			unlock_without_lock_006_glb_buf[i] = 'a';
			pthread_mutex_unlock(&unlock_without_lock_006_glb_mutex_1);
		}
	}
#if defined PRINT_DEBUG
	printf("Task6_1! Unlock without Lock, thread #%ld! buf %s\n", ip, unlock_without_lock_006_glb_buf);
#endif /* defined(PRINT_DEBUG) */
#endif /* defined(CHECKER_POLYSPACE) */

	return NULL;
}

void *unlock_without_lock_006_tsk_002(void *input)
{
#if !defined(CHECKER_POLYSPACE)
	long ip;
	ip = (long)input;
	ip = ip * 20;
	if (ip >= 0)
	{
		pthread_mutex_lock(&unlock_without_lock_006_glb_mutex_2);
		strcpy(unlock_without_lock_006_glb_buf, "STRI");
		pthread_mutex_unlock(&unlock_without_lock_006_glb_mutex_2);
	}
#if defined PRINT_DEBUG
	printf("Task6_2! Unlock without Lock, thread #%ld! buf = %s\n", ip, unlock_without_lock_006_glb_buf);
#endif /* defined(PRINT_DEBUG) */
#endif /* defined(CHECKER_POLYSPACE) */
	return NULL;
}

void unlock_without_lock_006()
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
		pthread_create(&th1, NULL, unlock_without_lock_006_tsk_001, (void *)t1);
		pthread_create(&th2, NULL, unlock_without_lock_006_tsk_002, (void *)t2);
		sleep(1);
	}

#endif /* defined(CHECKER_POLYSPACE) */
}
