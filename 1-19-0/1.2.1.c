/*
From:ITC
bug: 1
Concurrency defects
1.2
Double lock
 1.2.1
one thread one function
*/
#if defined(CHECKER_POLYSPACE)
#define NULL ((void *)0)
int rand(void);
#endif pthread_mutex_t double_lock_001_glb_mutex = PTHREAD_MUTEX_INITIALIZER;

#if defined(CHECKER_POLYSPACE)
void double_lock_001_glb_mutex_lock()
{
}
void double_lock_001_glb_mutex_unlock() {}
#endif /* #if defined(CHECKER_POLYSPACE) */
#ifndef __NO_POLYSPACE__

int double_lock_001_glb_data = 0;

void *double_lock_001_tsk_001(void *pram)
{
#if !defined(CHECKER_POLYSPACE)
	int ip = (int)pthread_self();
	pthread_mutex_lock(&double_lock_001_glb_mutex);
	double_lock_001_glb_data = (double_lock_001_glb_data % 100) + 1;
	pthread_mutex_unlock(&double_lock_001_glb_mutex);
	pthread_mutex_lock(&double_lock_001_glb_mutex); /*Tool should not detect this line as error*/ /*No ERROR:Double Lock*/
	double_lock_001_glb_data = (double_lock_001_glb_data % 100) + 1;
	printf("Task1! It's me, thread #%u!\n", ip);
	pthread_mutex_unlock(&double_lock_001_glb_mutex);
#endif /* defined(CHECKER_POLYSPACE) */
	return NULL;
}
void double_lock_001()
{
#if !defined(CHECKER_POLYSPACE)
	pthread_t tid1;
	pthread_mutex_init(&double_lock_001_glb_mutex, NULL);
	pthread_create(&tid1, NULL, double_lock_001_tsk_001, NULL);
	pthread_join(tid1, NULL);
	pthread_mutex_destroy(&double_lock_001_glb_mutex);
#endif /* defined(CHECKER_POLYSPACE) */
}
#if defined(CHECKER_POLYSPACE)
void double_lock_001_tskentry_001()
{
	while (1)
	{
		if (rand())
		{
			double_lock_001_tsk_001(NULL);
		}
	}
}
#endif /* defined(CHECKER_POLYSPACE) */ "
