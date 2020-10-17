/*
From:ITC
bug: 1
Concurrency defects
1.8
Unlock without lock
1.8.1
in same function using two thread
*/
#if defined(CHECKER_POLYSPACE)
#define NULL ((void *)0)
int rand(void);
#endif /* defined(CHECKER_POLYSPACE) */

pthread_mutex_t unlock_without_lock_001_glb_mutex = PTHREAD_MUTEX_INITIALIZER;

#if defined(CHECKER_POLYSPACE)
void unlock_without_lock_001_glb_mutex_lock()
{
}
void unlock_without_lock_001_glb_mutex_unlock() {}
#endif /* #if defined(CHECKER_POLYSPACE) */
#ifndef __NO_POLYSPACE__

int unlock_without_lock_001_glb_data = 0;

void *unlock_without_lock_001_tsk_001(void *pram)
{
#if !defined(CHECKER_POLYSPACE)
	char *th = (char *)pram;
	/* pthread_mutex_lock(&unlock_without_lock_001_glb_mutex); */
	unlock_without_lock_001_glb_data = (unlock_without_lock_001_glb_data % 100) + 1;
	pthread_mutex_unlock(&unlock_without_lock_001_glb_mutex); /*Tool should detect this line as error*/ /* ERROR:UnLock without lock */

	unsigned long ip = (unsigned long)pthread_self();
	printf(" Task1 !Unlock without Lock, threadID # % lu !thread no = % s \n ", ip, th);
#endif /* defined(CHECKER_POLYSPACE) */
	return NULL;
}

void unlock_without_lock_001()
{
#if !defined(CHECKER_POLYSPACE)
	pthread_t tid1, tid2;
	const char *t1 = " THREAD1 ";
	const char *t2 = " THREAD2 ";
	pthread_mutex_init(&unlock_without_lock_001_glb_mutex, NULL);
	pthread_create(&tid1, NULL, unlock_without_lock_001_tsk_001, (void *)t1);
	pthread_create(&tid2, NULL, unlock_without_lock_001_tsk_001, (void *)t2);
	pthread_join(tid1, NULL);
	pthread_join(tid2, NULL);
	pthread_mutex_destroy(&unlock_without_lock_001_glb_mutex);
#endif /* defined(CHECKER_POLYSPACE) */
}

#if defined(CHECKER_POLYSPACE)
void unlock_without_lock_001_tskentry_001()
{
	while (1)
	{
		if (rand())
		{
			unlock_without_lock_001_tsk_001(NULL);
		}
	}
}
#endif /* defined(CHECKER_POLYSPACE) */
