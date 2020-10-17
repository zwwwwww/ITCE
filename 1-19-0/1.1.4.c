/*
From:ITC
bug: 1
Concurrency defects
1.1
Dead lock
1.1.4
A->B->C  B->C->A
*/
#if defined(CHECKER_POLYSPACE)
int rand(void);
#endif pthread_mutex_t dead_lock_004_glb_mutexA_;
pthread_mutex_t dead_lock_004_glb_mutexB_;
pthread_mutex_t dead_lock_004_glb_mutexC_;
pthread_mutex_t *dead_lock_004_glb_mutexA = &dead_lock_004_glb_mutexA_;
pthread_mutex_t *dead_lock_004_glb_mutexB = &dead_lock_004_glb_mutexB_;
pthread_mutex_t *dead_lock_004_glb_mutexC = &dead_lock_004_glb_mutexC_;
#if defined(CHECKER_POLYSPACE)
void dead_lock_004_glb_mutexA_lock()
{
}
void dead_lock_004_glb_mutexA_unlock() {}
void dead_lock_004_glb_mutexB_lock() {}
void dead_lock_004_glb_mutexB_unlock() {}
void dead_lock_004_glb_mutexC_lock() {}
void dead_lock_004_glb_mutexC_unlock() {}
#endif /* #if defined(CHECKER_POLYSPACE) */

int dead_lock_004_glb_dataA = 0;
int dead_lock_004_glb_dataB = 0;
int dead_lock_004_glb_dataC = 0;

void *dead_lock_004_tsk_001(void *pram)
{
	/* lock A */
#if !defined(CHECKER_POLYSPACE)
	pthread_mutex_lock(dead_lock_004_glb_mutexA);
#else  /* ! defined(CHECKER_POLYSPACE) */
	pthread_mutex_lock(&dead_lock_004_glb_mutexA_);
#endif /* ! defined(CHECKER_POLYSPACE) */
	dead_lock_004_glb_dataA = (dead_lock_004_glb_dataA % 100) + 1;
	/* lock B */
#if !defined(CHECKER_POLYSPACE)
	pthread_mutex_lock(dead_lock_004_glb_mutexB);
#else  /* ! defined(CHECKER_POLYSPACE) */
	pthread_mutex_lock(&dead_lock_004_glb_mutexB_);
#endif /* ! defined(CHECKER_POLYSPACE) */
	dead_lock_004_glb_dataB = (dead_lock_004_glb_dataB % 100) + 1;
	/* lock C */
#if !defined(CHECKER_POLYSPACE)
	pthread_mutex_lock(dead_lock_004_glb_mutexC);
#else  /* ! defined(CHECKER_POLYSPACE) */
	pthread_mutex_lock(&dead_lock_004_glb_mutexC_);
#endif /* ! defined(CHECKER_POLYSPACE) */
	dead_lock_004_glb_dataC = (dead_lock_004_glb_dataC % 100) + 1;
#if !defined(CHECKER_POLYSPACE)
	pthread_mutex_unlock(dead_lock_004_glb_mutexC);
#else  /* ! defined(CHECKER_POLYSPACE) */
	pthread_mutex_unlock(&dead_lock_004_glb_mutexC_);
#endif /* ! defined(CHECKER_POLYSPACE) */

#if !defined(CHECKER_POLYSPACE)
	pthread_mutex_unlock(dead_lock_004_glb_mutexB);
#else  /* ! defined(CHECKER_POLYSPACE) */
	pthread_mutex_unlock(&dead_lock_004_glb_mutexB_);
#endif /* ! defined(CHECKER_POLYSPACE) */

#if !defined(CHECKER_POLYSPACE)
	pthread_mutex_unlock(dead_lock_004_glb_mutexA);
#else  /* ! defined(CHECKER_POLYSPACE) */
	pthread_mutex_unlock(&dead_lock_004_glb_mutexA_);
#endif /* ! defined(CHECKER_POLYSPACE) */
	return NULL;
}
void *dead_lock_004_tsk_002(void *pram)
{
	/* lock B */
#if !defined(CHECKER_POLYSPACE)
	pthread_mutex_lock(dead_lock_004_glb_mutexB); /*Tool should Not detect this line as error*/ /*No ERROR:Dead Lock*/
#else																							/* ! defined(CHECKER_POLYSPACE) */
	pthread_mutex_lock(&dead_lock_004_glb_mutexB_);
#endif																							/* ! defined(CHECKER_POLYSPACE) */
	dead_lock_004_glb_dataB = (dead_lock_004_glb_dataB % 100) + 1;
	/* lock C */
#if !defined(CHECKER_POLYSPACE)
	pthread_mutex_lock(dead_lock_004_glb_mutexC);
#else  /* ! defined(CHECKER_POLYSPACE) */
	pthread_mutex_lock(&dead_lock_004_glb_mutexC_);
#endif /* ! defined(CHECKER_POLYSPACE) */
	dead_lock_004_glb_dataC = (dead_lock_004_glb_dataC % 100) + 1;
#if !defined(CHECKER_POLYSPACE)
	pthread_mutex_unlock(dead_lock_004_glb_mutexC);
#else  /* ! defined(CHECKER_POLYSPACE) */
	pthread_mutex_unlock(&dead_lock_004_glb_mutexC_);
#endif /* ! defined(CHECKER_POLYSPACE) */
#if !defined(CHECKER_POLYSPACE)
	pthread_mutex_unlock(dead_lock_004_glb_mutexB);
#else  /* ! defined(CHECKER_POLYSPACE) */
	pthread_mutex_unlock(&dead_lock_004_glb_mutexB_);
#endif /* ! defined(CHECKER_POLYSPACE) */
	   /* lock A */
#if !defined(CHECKER_POLYSPACE)
	pthread_mutex_lock(dead_lock_004_glb_mutexA);
#else  /* ! defined(CHECKER_POLYSPACE) */
	pthread_mutex_lock(&dead_lock_004_glb_mutexA_);
#endif /* ! defined(CHECKER_POLYSPACE) */
	dead_lock_004_glb_dataA = (dead_lock_004_glb_dataA % 100) + 1;
#if !defined(CHECKER_POLYSPACE)
	pthread_mutex_unlock(dead_lock_004_glb_mutexA);
#else  /* ! defined(CHECKER_POLYSPACE) */
	pthread_mutex_unlock(&dead_lock_004_glb_mutexA_);
#endif /* ! defined(CHECKER_POLYSPACE) */
	return NULL;
}

void dead_lock_004()
{
	pthread_t tid1;
	pthread_t tid2;

	pthread_mutex_init(dead_lock_004_glb_mutexA, NULL);
	pthread_mutex_init(dead_lock_004_glb_mutexB, NULL);
	pthread_mutex_init(dead_lock_004_glb_mutexC, NULL);

	pthread_create(&tid1, NULL, dead_lock_004_tsk_001, NULL);
	pthread_create(&tid2, NULL, dead_lock_004_tsk_002, NULL);

	pthread_join(tid1, NULL);
	pthread_join(tid2, NULL);

	pthread_mutex_destroy(dead_lock_004_glb_mutexA);
	pthread_mutex_destroy(dead_lock_004_glb_mutexB);
	pthread_mutex_destroy(dead_lock_004_glb_mutexC);
}

#if defined(CHECKER_POLYSPACE)
void dead_lock_004_tskentry_001()
{
	while (1)
	{
		if (rand())
		{
			dead_lock_004_tsk_001(NULL);
		}
	}
}

void dead_lock_004_tskentry_002()
{
	while (1)
	{
		if (rand())
		{
			dead_lock_004_tsk_002(NULL);
		}
	}
}
#endif /* defined(CHECKER_POLYSPACE) */ "
