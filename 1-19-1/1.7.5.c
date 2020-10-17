/*
From:ITC
bug: 1
Concurrency defects
1.7
Race condition
1.7.5
4 threads access the same resources
*/
int rand(void);
int race_condition_005_glb_data = 0;
void *race_condition_005_tsk_001(void *pram)
{
#if !defined(CHECKER_POLYSPACE)
	/*pthread_mutex_lock(&race_condition_005_glb_mutex);*/
	race_condition_005_glb_data = (race_condition_005_glb_data % 100) + 1; /*Tool should detect this line as error*/ /*ERROR:Race condition*/
	/*pthread_mutex_unlock(&race_condition_005_glb_mutex);*/

	unsigned long ip = (unsigned long)pthread_self();
	printf(" Task5 !race condition, threadID # % lu !gbl1 = % d \n ", ip, race_condition_005_glb_data);
#endif /* defined(CHECKER_POLYSPACE) */
	return NULL;
}

void race_condition_005()
{
#if !defined(CHECKER_POLYSPACE)
	pthread_t tid1, tid2, tid3, tid4;
	/*pthread_mutex_init(&race_condition_005_glb_mutex, NULL);*/
	pthread_create(&tid1, NULL, race_condition_005_tsk_001, NULL);
	pthread_create(&tid2, NULL, race_condition_005_tsk_001, NULL);
	pthread_create(&tid3, NULL, race_condition_005_tsk_001, NULL);
	pthread_create(&tid4, NULL, race_condition_005_tsk_001, NULL);
	pthread_join(tid1, NULL);
	pthread_join(tid2, NULL);
	pthread_join(tid3, NULL);
	pthread_join(tid4, NULL);
	/*pthread_mutex_destroy(&race_condition_005_glb_mutex);*/
#endif /* defined(CHECKER_POLYSPACE) */
}

#if defined(CHECKER_POLYSPACE)
void race_condition_005_tskentry_001()
{
	while (1)
	{
		if (rand())
		{
			race_condition_005_tsk_001(NULL);
		}
	}
}
#endif /* defined(CHECKER_POLYSPACE) */
