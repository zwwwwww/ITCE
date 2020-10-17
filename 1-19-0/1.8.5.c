/*
From:ITC
bug: 1
Concurrency defects
1.8
Unlock without lock
1.8.5
in else condition
*/
pthread_mutex_t unlock_without_lock_005_glb_mutex = PTHREAD_MUTEX_INITIALIZER;
int unlock_without_lock_005_glb_data = 0;

#define NO_THREAD 0
int unlock_without_lock_005_thread_set = 1;

void *unlock_without_lock_005_tsk_001(void *pram)
{
#if !defined(CHECKER_POLYSPACE)
	if (unlock_without_lock_005_thread_set == NO_THREAD)
	{
		;
	}
	else
	{
		pthread_mutex_lock(&unlock_without_lock_005_glb_mutex);
		unlock_without_lock_005_glb_data = (unlock_without_lock_005_glb_data % 100) + 5;
		pthread_mutex_unlock(&unlock_without_lock_005_glb_mutex); /*Tool should not detect this line as error*/ /* No ERROR:UnLock without lock */

		unsigned long ip = (unsigned long)pthread_self();
		printf("Task5! Unlock without Lock, threadID# %lu! gbl5 = %d \n", ip, unlock_without_lock_005_glb_data);
#endif /* defined(CHECKER_POLYSPACE) */
	}
	return NULL;
}

void unlock_without_lock_005()
{
#if !defined(CHECKER_POLYSPACE)
	if (unlock_without_lock_005_thread_set == NO_THREAD)
	{
		;
	}
	else
	{
		pthread_t tid1;
		pthread_mutex_init(&unlock_without_lock_005_glb_mutex, NULL);
		pthread_create(&tid1, NULL, unlock_without_lock_005_tsk_001, NULL);
		pthread_join(tid1, NULL);
		pthread_mutex_destroy(&unlock_without_lock_005_glb_mutex);
	}
#endif /* defined(CHECKER_POLYSPACE) */
}
