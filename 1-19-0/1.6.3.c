/*
From:ITC
bug: 1
Concurrency defects
1.6
Long lock
1.6.3
across the function long time sleep
*/
int rand(void);
pthread_mutex_t sleep_lock_003_glb_mutex_;
pthread_mutex_t *sleep_lock_003_glb_mutex = &sleep_lock_003_glb_mutex_;
#if defined(CHECKER_POLYSPACE)
void sleep_lock_003_glb_mutex_lock()
{
}
void sleep_lock_003_glb_mutex_unlock() {}
#endif /* #if defined(CHECKER_POLYSPACE) */

int sleep_lock_003_glb_data = 0;

void sleep_lock_003_func_001()
{
	/* Do nothing */
	/*Tool should not detect this line as error*/ /*No Error:Long Sleep */
}

void *sleep_lock_003_tsk_001(void *pram)
{
	pthread_mutex_lock(sleep_lock_003_glb_mutex);
	sleep_lock_003_glb_data = (sleep_lock_003_glb_data % 100) + 1;

	sleep_lock_003_func_001();

	pthread_mutex_unlock(sleep_lock_003_glb_mutex);
	return NULL;
}

void sleep_lock_003()
{
	pthread_t tid1;
	pthread_mutex_init(sleep_lock_003_glb_mutex, NULL);
	pthread_create(&tid1, NULL, sleep_lock_003_tsk_001, NULL);
	pthread_join(tid1, NULL);
	pthread_mutex_destroy(sleep_lock_003_glb_mutex);
}

#if defined(CHECKER_POLYSPACE)
void sleep_lock_003_tskentry_001()
{
	while (1)
	{
		if (rand())
		{
			sleep_lock_003_tsk_001(NULL);
		}
	}
}
#endif /* defined(CHECKER_POLYSPACE) */ "
