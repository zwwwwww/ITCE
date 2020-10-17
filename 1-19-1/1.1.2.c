/*
From:ITC
bug: 1
Concurrency defects
1.1
dead lock
 1.1.2
A->B   B->C  C->A
*/
#if defined(CHECKER_POLYSPACE)
int rand(void);
#endif
pthread_mutex_t dead_lock_002_glb_mutexA = PTHREAD_MUTEX_INITIALIZER;
pthread_mutex_t dead_lock_002_glb_mutexB = PTHREAD_MUTEX_INITIALIZER;
pthread_mutex_t dead_lock_002_glb_mutexC = PTHREAD_MUTEX_INITIALIZER;
#if defined(CHECKER_POLYSPACE)
void dead_lock_002_glb_mutexA_lock()
{
}
void dead_lock_002_glb_mutexA_unlock() {}
void dead_lock_002_glb_mutexB_lock() {}
void dead_lock_002_glb_mutexB_unlock() {}
void dead_lock_002_glb_mutexC_lock() {}
void dead_lock_002_glb_mutexC_unlock() {}
#endif /* #if defined(CHECKER_POLYSPACE) */
int dead_lock_002_glb_dataA = 0;
int dead_lock_002_glb_dataB = 0;
int dead_lock_002_glb_dataC = 0;
void *dead_lock_002_tsk_001(void *pram)
{
	/* lock A */
#if !defined(CHECKER_POLYSPACE)
	pthread_mutex_lock(&dead_lock_002_glb_mutexA);
#endif /* ! defined(CHECKER_POLYSPACE) */
	dead_lock_002_glb_dataA = (dead_lock_002_glb_dataA % 100) + 1;
	/* lock B */
#if !defined(CHECKER_POLYSPACE)
	pthread_mutex_lock(&dead_lock_002_glb_mutexB);
#endif /* ! defined(CHECKER_POLYSPACE) */
	dead_lock_002_glb_dataB = (dead_lock_002_glb_dataB % 100) + 1;
#if !defined(CHECKER_POLYSPACE)
	pthread_mutex_unlock(&dead_lock_002_glb_mutexB);
#endif /* ! defined(CHECKER_POLYSPACE) */
#if !defined(CHECKER_POLYSPACE)
	pthread_mutex_unlock(&dead_lock_002_glb_mutexA);
#endif /* ! defined(CHECKER_POLYSPACE) */
	return NULL;
}
void *dead_lock_002_tsk_002(void *pram)
{
	/* lock B */
#if !defined(CHECKER_POLYSPACE)
	pthread_mutex_lock(&dead_lock_002_glb_mutexB);
#endif /* ! defined(CHECKER_POLYSPACE) */
	dead_lock_002_glb_dataB = (dead_lock_002_glb_dataB % 100) + 1;
	/* lock C */
#if !defined(CHECKER_POLYSPACE)
	pthread_mutex_lock(&dead_lock_002_glb_mutexC);
#endif /* ! defined(CHECKER_POLYSPACE) */
	dead_lock_002_glb_dataC = (dead_lock_002_glb_dataC % 100) + 1;
#if !defined(CHECKER_POLYSPACE)
	pthread_mutex_unlock(&dead_lock_002_glb_mutexC);
#endif /* ! defined(CHECKER_POLYSPACE) */
#if !defined(CHECKER_POLYSPACE)
	pthread_mutex_unlock(&dead_lock_002_glb_mutexB);
#endif /* ! defined(CHECKER_POLYSPACE) */
	return NULL;
}
void *dead_lock_002_tsk_003(void *pram)
{
	/* lock C */
#if !defined(CHECKER_POLYSPACE)
	pthread_mutex_lock(&dead_lock_002_glb_mutexC); /*Tool should detect this line as error*/ /*ERROR:Dead Lock*/
#endif																						 /* ! defined(CHECKER_POLYSPACE) */
	dead_lock_002_glb_dataC = (dead_lock_002_glb_dataC % 100) + 1;
	/* lock A */
#if !defined(CHECKER_POLYSPACE)
	pthread_mutex_lock(&dead_lock_002_glb_mutexA);
#endif /* ! defined(CHECKER_POLYSPACE) */
	dead_lock_002_glb_dataA = (dead_lock_002_glb_dataA % 100) + 1;
#if !defined(CHECKER_POLYSPACE)
	pthread_mutex_unlock(&dead_lock_002_glb_mutexA);
#endif /* ! defined(CHECKER_POLYSPACE) */
#if !defined(CHECKER_POLYSPACE)
	pthread_mutex_unlock(&dead_lock_002_glb_mutexC);
#endif /* ! defined(CHECKER_POLYSPACE) */
	return NULL;
}
void dead_lock_002()
{
	pthread_t tid1;
	pthread_t tid2;
	pthread_t tid3;
	pthread_mutex_init(&dead_lock_002_glb_mutexA, NULL);
	pthread_mutex_init(&dead_lock_002_glb_mutexB, NULL);
	pthread_mutex_init(&dead_lock_002_glb_mutexC, NULL);
	pthread_create(&tid1, NULL, dead_lock_002_tsk_001, NULL);
	pthread_create(&tid2, NULL, dead_lock_002_tsk_002, NULL);
	pthread_create(&tid3, NULL, dead_lock_002_tsk_003, NULL);
	pthread_join(tid1, NULL);
	pthread_join(tid2, NULL);
	pthread_join(tid3, NULL);
	pthread_mutex_destroy(&dead_lock_002_glb_mutexA);
	pthread_mutex_destroy(&dead_lock_002_glb_mutexB);
	pthread_mutex_destroy(&dead_lock_002_glb_mutexC);
}
#if defined(CHECKER_POLYSPACE)
void dead_lock_002_tskentry_001()
{
	while (1)
	{
		if (rand())
		{
			dead_lock_002_tsk_001(NULL);
		}
	}
}
void dead_lock_002_tskentry_002()
{
	while (1)
	{
		if (rand())
		{
			dead_lock_002_tsk_002(NULL);
		}
	}
}
void dead_lock_002_tskentry_003()
{
	while (1)
	{
		if (rand())
		{
			dead_lock_002_tsk_003(NULL);
		}
	}
}
#endif /* defined(CHECKER_POLYSPACE) */
