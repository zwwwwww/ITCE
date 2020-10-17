/*
From:ITC
bug: 1
Concurrency defects
1.1
Dead lock
 1.1.1
A->B   B->A
*/
#if defined(CHECKER_POLYSPACE)
int rand(void);
#endif
pthread_mutex_t dead_lock_001_glb_mutexA = PTHREAD_MUTEX_INITIALIZER;
pthread_mutex_t dead_lock_001_glb_mutexB = PTHREAD_MUTEX_INITIALIZER;
#if defined(CHECKER_POLYSPACE)
void dead_lock_001_glb_mutexA_lock()
{
}
void dead_lock_001_glb_mutexA_unlock() {}
void dead_lock_001_glb_mutexB_lock() {}
void dead_lock_001_glb_mutexB_unlock() {}
#endif /* #if defined(CHECKER_POLYSPACE) */

int dead_lock_001_glb_dataA = 10;
int dead_lock_001_glb_dataB = 10;

void *dead_lock_001_tsk_001(void *pram)
{
	/* lock A */
#if !defined(CHECKER_POLYSPACE)
	pthread_mutex_lock(&dead_lock_001_glb_mutexA);
#endif /* ! defined(CHECKER_POLYSPACE) */
	dead_lock_001_glb_dataA = (dead_lock_001_glb_dataA % 100) + 10;
	printf(" Task1 !dead_lock = % d \n ", dead_lock_001_glb_dataA);
	/* lock B */
#if !defined(CHECKER_POLYSPACE)
	pthread_mutex_lock(&dead_lock_001_glb_mutexB);
#endif
	dead_lock_001_glb_dataB = (dead_lock_001_glb_dataB % 100) + 20;
#if !defined(CHECKER_POLYSPACE)
	pthread_mutex_unlock(&dead_lock_001_glb_mutexB);
#endif
#if !defined(CHECKER_POLYSPACE)
	pthread_mutex_unlock(&dead_lock_001_glb_mutexA);
#endif
	return NULL;
}
void *dead_lock_001_tsk_002(void *pram)
{
	/* lock B */
#if !defined(CHECKER_POLYSPACE)
	pthread_mutex_lock(&dead_lock_001_glb_mutexB); /*Tool should detect this line as error*/ /*ERROR:Dead Lock*/
#endif
	dead_lock_001_glb_dataA = (dead_lock_001_glb_dataA % 100) + 1;
	/* lock A */
#if !defined(CHECKER_POLYSPACE)
	pthread_mutex_lock(&dead_lock_001_glb_mutexA);
#endif /* ! defined(CHECKER_POLYSPACE) */
	dead_lock_001_glb_dataB = (dead_lock_001_glb_dataB % 100) + 1;
#if !defined(CHECKER_POLYSPACE)
	pthread_mutex_unlock(&dead_lock_001_glb_mutexA);
#endif
#if !defined(CHECKER_POLYSPACE)
	pthread_mutex_unlock(&dead_lock_001_glb_mutexB);
#endif
	return NULL;
}
void dead_lock_001()
{
	pthread_t tid1;
	pthread_t tid2;
	pthread_mutex_init(&dead_lock_001_glb_mutexA, NULL);
	pthread_mutex_init(&dead_lock_001_glb_mutexB, NULL);
	pthread_create(&tid1, NULL, dead_lock_001_tsk_001, NULL);
	pthread_create(&tid2, NULL, dead_lock_001_tsk_002, NULL);
	pthread_join(tid1, NULL);
	pthread_join(tid2, NULL);
	pthread_mutex_destroy(&dead_lock_001_glb_mutexA);
	pthread_mutex_destroy(&dead_lock_001_glb_mutexB);
}
#if defined(CHECKER_POLYSPACE)
void dead_lock_001_tskentry_001()
{
	while (1)
	{
		if (rand())
		{
			dead_lock_001_tsk_001(NULL);
		}
	}
}

void dead_lock_001_tskentry_002()
{
	while (1)
	{
		if (rand())
		{
			dead_lock_001_tsk_002(NULL);
		}
	}
}
#endif
