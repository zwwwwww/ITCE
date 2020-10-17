/*
From:ITC
8
Stack related defects 
8.1
Cross thread stack access
8.1.1
Cross thread stack access in same function using two thread
*/
#if defined(CHECKER_POLYSPACE)
#define NULL ((void *)0)
int rand(void);
pthread_mutex_t st_cross_thread_access_001_glb_mutex = PTHREAD_MUTEX_INITIALIZER;
pthread_mutex_t st_cross_thread_access_001_glb_mutex_1 = PTHREAD_MUTEX_INITIALIZER;

#if defined(CHECKER_POLYSPACE)
void st_cross_thread_access_001_glb_mutex_lock()
{
}
void st_cross_thread_access_001_glb_mutex_unlock() {}
#endif /* \
 #if defined(CHECKER_POLYSPACE) */
#ifndef __NO_POLYSPACE__

int st_cross_thread_access_001_glb_data = 0;
int *st_cross_thread_access_001_glb_ptr;

void *st_cross_thread_access_001_tsk_001(void *pram)
{
#if !defined(CHECKER_POLYSPACE)
	char *th = (char *)pram;
	int arr[10];
	st_cross_thread_access_001_glb_ptr = arr;
	arr[0] = 10;
	*st_cross_thread_access_001_glb_ptr = 200;
	pthread_mutex_lock(&st_cross_thread_access_001_glb_mutex);
	st_cross_thread_access_001_glb_data = (st_cross_thread_access_001_glb_data % 100) + 1;

	pthread_mutex_unlock(&st_cross_thread_access_001_glb_mutex);

	unsigned long ip = (unsigned long)pthread_self();
	printf("" Task1 !Cross thread stack access, threadID # % lu !thread no = % s % d\n "", ip, th, *st_cross_thread_access_001_glb_ptr);
#endif /* defined(CHECKER_POLYSPACE) */
	return NULL;
}

void *st_cross_thread_access_001_tsk_002(void *pram)
{
#if !defined(CHECKER_POLYSPACE)
	char *th = (char *)pram;
	/* *st_cross_thread_access_001_glb_ptr = 200; */ /*Tool should not detect this line as error*/ /*No ERROR:Cross thread stack access error*/
	pthread_mutex_lock(&st_cross_thread_access_001_glb_mutex_1);
	st_cross_thread_access_001_glb_data = (st_cross_thread_access_001_glb_data % 100) + 1;
	pthread_mutex_unlock(&st_cross_thread_access_001_glb_mutex_1);

	unsigned long ip = (unsigned long)pthread_self();
	printf("" Task1 !Cross thread stack access, threadID # % lu !thread no = % s \n "", ip, th);
#endif /* defined(CHECKER_POLYSPACE) */
	return NULL;
}

void st_cross_thread_access_001()
{
#if !defined(CHECKER_POLYSPACE)
	pthread_t tid1, tid2;
	const char *t1 = "" THREAD1 "";
	const char *t2 = "" THREAD2 "";
	pthread_mutex_init(&st_cross_thread_access_001_glb_mutex, NULL);
	pthread_create(&tid1, NULL, st_cross_thread_access_001_tsk_001, (void *)t1);
	sleep(1);
	pthread_mutex_init(&st_cross_thread_access_001_glb_mutex_1, NULL);
	pthread_create(&tid2, NULL, st_cross_thread_access_001_tsk_002, (void *)t2);
	pthread_join(tid1, NULL);
	pthread_join(tid1, NULL);
	pthread_mutex_destroy(&st_cross_thread_access_001_glb_mutex);
	pthread_mutex_destroy(&st_cross_thread_access_001_glb_mutex_1);
#endif /* defined(CHECKER_POLYSPACE) */
}

#if defined(CHECKER_POLYSPACE)
void st_cross_thread_access_001_tskentry_001()
{
	while (1)
	{
		if (rand())
		{
			st_cross_thread_access_001_tsk_001(NULL);
		}
	}
}
#endif /* defined(CHECKER_POLYSPACE) */
