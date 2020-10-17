/*
From:ITC
bug: 1
Concurrency defects
1.7
Race condition
1.7.6

*/
int rand(void);

pthread_mutex_t race_condition_006_glb_mutex = PTHREAD_MUTEX_INITIALIZER;
#if defined(CHECKER_POLYSPACE)
void race_condition_006_glb_mutex_lock()
{
}
void race_condition_006_glb_mutex_unlock() {}
#endif /* #if defined(CHECKER_POLYSPACE) */

int race_condition_006_glb_data = 0;

void *race_condition_006_tsk_001(void *pram)
{
#if !defined(CHECKER_POLYSPACE)
	/*pthread_mutex_lock(&race_condition_006_glb_mutex);*/
	race_condition_006_glb_data = (race_condition_006_glb_data % 100) + 1;
	/*pthread_mutex_unlock(&race_condition_006_glb_mutex);*/

	/*pthread_mutex_lock(&race_condition_006_glb_mutex);*/
	race_condition_006_glb_data = (race_condition_006_glb_data % 100) + 1; /*Tool should detect this line as error*/ /*ERROR:Race condition*/
#if defined PRINT_DEBUG
	unsigned long ip = (unsigned long)pthread_self();
	printf(" Task2 !race condition, threadID # % lu !gbl2 = % d \n ", ip, race_condition_006_glb_data);
#endif /* defined(PRINT_DEBUG) */
	   /*pthread_mutex_unlock(&race_condition_006_glb_mutex);*/

#endif /* defined(CHECKER_POLYSPACE) */
	return NULL;
}

void race_condition_006()
{
#if !defined(CHECKER_POLYSPACE)
	pthread_t tid1, tid2;
	pthread_mutex_init(&race_condition_006_glb_mutex, NULL);
	pthread_create(&tid1, NULL, race_condition_006_tsk_001, NULL);
	pthread_create(&tid2, NULL, race_condition_006_tsk_001, NULL);
	pthread_join(tid1, NULL);
	pthread_join(tid2, NULL);

#endif /* defined(CHECKER_POLYSPACE) */
}
#if defined(CHECKER_POLYSPACE)
void race_condition_006_tskentry_001()
{
	while (1)
	{
		if (rand())
		{
			race_condition_006_tsk_001(NULL);
		}
	}
}
#endif /* defined(CHECKER_POLYSPACE) */
