/*
From:ITC
8
Stack related defects 
8.1
Cross thread stack access
8.1.3
"Cross thread stack access over multiple functions , 2 threads,based on return value of function"
*/
#if defined(CHECKER_POLYSPACE)
#define NULL ((void *)0)
int rand(void);
pthread_mutex_t st_cross_thread_access_003_glb_mutex = PTHREAD_MUTEX_INITIALIZER;
pthread_mutex_t st_cross_thread_access_003_glb_mutex_1 = PTHREAD_MUTEX_INITIALIZER;

#if defined(CHECKER_POLYSPACE)
void st_cross_thread_access_003_glb_mutex_lock()
{
}
void st_cross_thread_access_003_glb_mutex_unlock() {}
#endif /* \
 #if defined(CHECKER_POLYSPACE) */

float st_cross_thread_access_003_glb_data = 1000.0;
float st_cross_thread_access_003_glb_data1 = 10.0;
float *st_cross_thread_access_003_glb_ptr = &st_cross_thread_access_003_glb_data1;

int st_cross_thread_access_003_func_002(int a);
void *st_cross_thread_access_003_tsk_001(void *pram)
{
	float fptr = 50.2;
#if !defined(CHECKER_POLYSPACE)
	if (st_cross_thread_access_003_func_002(10) > 1)
	{
		pthread_mutex_lock(&st_cross_thread_access_003_glb_mutex);
		st_cross_thread_access_003_glb_data = (st_cross_thread_access_003_glb_data) + 1.2;
		st_cross_thread_access_003_glb_ptr = &fptr;
#if defined PRINT_DEBUG
		intptr_t ip = (intptr_t)pram;
		printf(" Task3 !Cross thread stack access, thread # % d !gbl3 = % f \n ", ip, st_cross_thread_access_003_glb_data);
#endif /* defined(PRINT_DEBUG) */
		pthread_mutex_unlock(&st_cross_thread_access_003_glb_mutex);
	}
#endif /* ! defined(CHECKER_POLYSPACE) */
	return NULL;
}

int st_cross_thread_access_003_func_002(int a)
{
	int ret = 0;
	if (a > 1)
	{
		ret = a++;
	}
	return ret;
}

void *st_cross_thread_access_003_tsk_002(void *pram)
{
#if !defined(CHECKER_POLYSPACE)

	if (st_cross_thread_access_003_func_002(10) != 0)
	{
		pthread_mutex_lock(&st_cross_thread_access_003_glb_mutex_1);
		*st_cross_thread_access_003_glb_ptr = 5.3; /*Tool should detect this line as error*/ /*ERROR:Cross thread stack access error*/
		st_cross_thread_access_003_glb_data = (st_cross_thread_access_003_glb_data) + 3.5;
		pthread_mutex_unlock(&st_cross_thread_access_003_glb_mutex_1);
	}
#endif /* defined(CHECKER_POLYSPACE) */
	return NULL;
}

void st_cross_thread_access_003()
{
#if !defined(CHECKER_POLYSPACE)
	pthread_t tid1, tid2;
	intptr_t t1 = 10, t2 = 20;
	pthread_mutex_init(&st_cross_thread_access_003_glb_mutex, NULL);
	pthread_create(&tid1, NULL, st_cross_thread_access_003_tsk_001, (void *)t1);
	pthread_create(&tid2, NULL, st_cross_thread_access_003_tsk_002, (void *)t2);
	pthread_join(tid1, NULL);
	pthread_join(tid2, NULL);
	pthread_mutex_destroy(&st_cross_thread_access_003_glb_mutex);
#endif /* defined(CHECKER_POLYSPACE) */
}

#if defined(CHECKER_POLYSPACE)
void st_cross_thread_access_003_tskentry_001()
{
	while (1)
	{
		if (rand())
		{
			st_cross_thread_access_003_tsk_001(NULL);
		}
	}
}
#endif /* defined(CHECKER_POLYSPACE) */
