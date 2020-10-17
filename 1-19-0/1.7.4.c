/*
From:ITC
bug: 1
Concurrency defects
1.7
Race condition
1.7.4
10 threads access the same resources
*/
pthread_mutex_t race_condition_004_glb_mutex = PTHREAD_MUTEX_INITIALIZER;

#if defined(CHECKER_POLYSPACE)
void race_condition_004_glb_mutex_lock()
{
}
void race_condition_004_glb_mutex_unlock() {}
#endif /* #if defined(CHECKER_POLYSPACE) */

int race_condition_004_glb_data = 0;

void *race_condition_004_tsk_001(void *pram)
{
#if !defined(CHECKER_POLYSPACE)
	pthread_mutex_lock(&race_condition_004_glb_mutex);
	race_condition_004_glb_data = (race_condition_004_glb_data % 100) + 1;
	pthread_mutex_unlock(&race_condition_004_glb_mutex);

	unsigned long ip = (unsigned long)pthread_self();
	printf(" Task1 !Lock Never Unlock, threadID # % lu !gbl1 = % d \n ", ip, race_condition_004_glb_data);
#endif /* defined(CHECKER_POLYSPACE) */
	return NULL;
}

void race_condition_004()
{
#if !defined(CHECKER_POLYSPACE)
	pthread_t tid1;
	pthread_mutex_init(&race_condition_004_glb_mutex, NULL);
	pthread_create(&tid1, NULL, race_condition_004_tsk_001, NULL);
	pthread_join(tid1, NULL);
	pthread_mutex_destroy(&race_condition_004_glb_mutex);
#endif /* defined(CHECKER_POLYSPACE) */
}
