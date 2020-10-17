/*
From:ITC
8
Stack related defects 
8.1
Cross thread stack access
8.1.2
unLocking without locking in same function using two thread inside a if condition
*/
#if defined(CHECKER_POLYSPACE)
#define NULL ((void *)0)
int rand(void);
pthread_mutex_t st_cross_thread_access_002_glb_mutex = PTHREAD_MUTEX_INITIALIZER;
pthread_mutex_t st_cross_thread_access_002_glb_mutex_1 = PTHREAD_MUTEX_INITIALIZER;

#if defined(CHECKER_POLYSPACE)
void st_cross_thread_access_002_glb_mutex_lock()
{
}
void st_cross_thread_access_002_glb_mutex_unlock() {}
#endif /* \
 #if defined(CHECKER_POLYSPACE) */

unsigned long st_cross_thread_access_002_glb_data = 0;
int const st_cross_thread_access_002_var = 10;
int arr1[5] = {1, 2, 3, 4, 5};
int *st_cross_thread_access_002_glb_ptr = arr1;
void *st_cross_thread_access_002_tsk_001(void *pram)
{
#if !defined(CHECKER_POLYSPACE)
	int arr[5] = {10, 20, 30, 40, 50};
	if (st_cross_thread_access_002_var == (intptr_t)pram)
	{
		pthread_mutex_lock(&st_cross_thread_access_002_glb_mutex);
		st_cross_thread_access_002_glb_data = (st_cross_thread_access_002_glb_data % 100) + 1;
		st_cross_thread_access_002_glb_ptr = arr;
		*st_cross_thread_access_002_glb_ptr = 200.0;
		pthread_mutex_unlock(&st_cross_thread_access_002_glb_mutex);
	}
	if (st_cross_thread_access_002_var == (intptr_t)pram)
	{
		pthread_mutex_lock(&st_cross_thread_access_002_glb_mutex);
		st_cross_thread_access_002_glb_data = (st_cross_thread_access_002_glb_data % 100) + 1;
#if defined PRINT_DEBUG
		unsigned long ip = (unsigned long)pthread_self();
		printf(" Task2 !Cross thread stack access, threadID # % lu !gbl2 = % lu \n ", ip, st_cross_thread_access_002_glb_data);
#endif /* defined(PRINT_DEBUG) */
		pthread_mutex_unlock(&st_cross_thread_access_002_glb_mutex);
	}
#endif /* defined(CHECKER_POLYSPACE) */
	return NULL;
}

void *st_cross_thread_access_002_tsk_002(void *pram)
{
#if !defined(CHECKER_POLYSPACE)
	if (st_cross_thread_access_002_var == (intptr_t)pram)
	{
		pthread_mutex_lock(&st_cross_thread_access_002_glb_mutex_1);
		st_cross_thread_access_002_glb_data = (st_cross_thread_access_002_glb_data % 100) + 1;
		*st_cross_thread_access_002_glb_ptr = 200.0; /*Tool should detect this line as error*/ /*ERROR:Cross thread stack access error*/
		pthread_mutex_unlock(&st_cross_thread_access_002_glb_mutex_1);
	}
	if (st_cross_thread_access_002_var == (intptr_t)pram)
	{
		pthread_mutex_lock(&st_cross_thread_access_002_glb_mutex_1);
		st_cross_thread_access_002_glb_data = (st_cross_thread_access_002_glb_data % 100) + 1;
#if defined PRINT_DEBUG
		unsigned long ip = (unsigned long)pthread_self();
		printf(" Task2 !Cross thread stack access, threadID # % lu !gbl2 = % lu \n ", ip, st_cross_thread_access_002_glb_data);
#endif /* defined(PRINT_DEBUG) */
		pthread_mutex_unlock(&st_cross_thread_access_002_glb_mutex_1);
	}
#endif /* defined(CHECKER_POLYSPACE) */
	return NULL;
}

void st_cross_thread_access_002()
{
#if !defined(CHECKER_POLYSPACE)
	pthread_t tid1, tid2;
	intptr_t st_cross_thread_access_002_t1 = 10;
	intptr_t st_cross_thread_access_002_t2 = 10;
	pthread_mutex_init(&st_cross_thread_access_002_glb_mutex, NULL);
	pthread_create(&tid1, NULL, st_cross_thread_access_002_tsk_001, (void *)st_cross_thread_access_002_t1);
	sleep(1);
	pthread_create(&tid2, NULL, st_cross_thread_access_002_tsk_002, (void *)st_cross_thread_access_002_t2);
	pthread_join(tid1, NULL);
	pthread_join(tid2, NULL);
#endif /* defined(CHECKER_POLYSPACE) */
}

#if defined(CHECKER_POLYSPACE)
void st_cross_thread_access_002_tskentry_001()
{
	while (1)
	{
		if (rand())
		{
			st_cross_thread_access_002_tsk_001(NULL);
		}
	}
}
#endif /* defined(CHECKER_POLYSPACE) */
