/*
From:ITC
bug: 1
Concurrency defects
1.7
Race condition
1.7.7

*/
int rand(void);
pthread_mutex_t race_condition_007_glb_mutex = PTHREAD_MUTEX_INITIALIZER;
#if defined(CHECKER_POLYSPACE)
void race_condition_007_glb_mutex_lock()
{
}
void race_condition_007_glb_mutex_unlock() {}
#endif /* #if defined(CHECKER_POLYSPACE) */

float race_condition_007_glb_data = 1000.0;

void race_condition_007_func_001(void *pram)
{
#if !defined(CHECKER_POLYSPACE)
	/*pthread_mutex_lock (&race_condition_007_glb_mutex);*/
	race_condition_007_glb_data = (race_condition_007_glb_data) + 1.2; /*Tool should detect this line as error*/ /*ERROR:Race condition*/

#if defined PRINT_DEBUG
	int ip = (int)pram;
	printf(" Task3 !race condition, thread # % d !gbl3 = % f \n ", ip, race_condition_007_glb_data);
#endif /* defined(PRINT_DEBUG) */

	/*pthread_mutex_unlock (&race_condition_007_glb_mutex);*/
#endif /* ! defined(CHECKER_POLYSPACE) */
}

void *race_condition_007_tsk_001(void *pram)
{
#if !defined(CHECKER_POLYSPACE)

	/*pthread_mutex_lock(&race_condition_007_glb_mutex);*/
	race_condition_007_glb_data = (race_condition_007_glb_data) + 3.5;
	race_condition_007_func_001(pram);
	/*pthread_mutex_unlock(&race_condition_007_glb_mutex);*/
#endif /* defined(CHECKER_POLYSPACE) */
	return NULL;
}

void race_condition_007()
{
#if !defined(CHECKER_POLYSPACE)
	pthread_t tid1, tid2;
	intptr_t t1 = 10, t2 = 20;
	/*pthread_mutex_init(&race_condition_007_glb_mutex, NULL);*/
	pthread_create(&tid1, NULL, race_condition_007_tsk_001, (void *)t1);
	pthread_create(&tid2, NULL, race_condition_007_tsk_001, (void *)t2);
	pthread_join(tid1, NULL);
	pthread_join(tid2, NULL);
	/*pthread_mutex_destroy(&race_condition_007_glb_mutex);*/
#endif /* defined(CHECKER_POLYSPACE) */
}
#if defined(CHECKER_POLYSPACE)
void race_condition_007_tskentry_001()
{
	while (1)
	{
		if (rand())
		{
			race_condition_007_tsk_001(NULL);
		}
	}
}
#endif /* defined(CHECKER_POLYSPACE) */
