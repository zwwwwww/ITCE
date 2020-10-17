/*
From:ITC
8
Stack related defects 
8.1
Cross thread stack access
8.1.6
Cross thread stack access over multiple functions using 2 threads created in else condition
*/
#if defined(CHECKER_POLYSPACE)
#define NULL ((void *)0)
int rand(void);
pthread_mutex_t st_cross_thread_access_006_glb_mutex_1 = PTHREAD_MUTEX_INITIALIZER;
pthread_mutex_t st_cross_thread_access_006_glb_mutex_2 = PTHREAD_MUTEX_INITIALIZER;
#define CREATE_THREAD 1
typedef struct
{
	int a;
	int b;
} st_cross_thread_access_006_s_001;
st_cross_thread_access_006_s_001 s1 = {10, 20};
st_cross_thread_access_006_s_001 *sptr = &s1;
void *st_cross_thread_access_006_tsk_001(void *input)
{
#if !defined(CHECKER_POLYSPACE)
	long ip;
	int i;
	ip = (long)input;
	ip = ip * 10;
	st_cross_thread_access_006_s_001 s = {1, 2};
	for (i = 0; i <= 4; i++)
	{
		if (ip >= 0)
		{
			pthread_mutex_lock(&st_cross_thread_access_006_glb_mutex_1);
			sptr = &s;
			pthread_mutex_unlock(&st_cross_thread_access_006_glb_mutex_1);
		}
	}
#if defined PRINT_DEBUG
	printf("" Task6_1 !Cross thread stack access, thread # % ld !aa = % d\n "", ip, sptr->a);
#endif /* defined(PRINT_DEBUG) */
#endif /* defined(CHECKER_POLYSPACE) */
	return NULL;
}

void *st_cross_thread_access_006_tsk_002(void *input)
{
#if !defined(CHECKER_POLYSPACE)
	long ip;
	int i;
	ip = (long)input;
	ip = ip * 20;
	for (i = 0; i <= 4; i++)
	{
		if (ip >= 0)
		{
			pthread_mutex_lock(&st_cross_thread_access_006_glb_mutex_2);
			/*sptr->a = 100;*/ /*Tool should not detect this line as error*/ /*No ERROR:Cross thread stack access error*/
			pthread_mutex_unlock(&st_cross_thread_access_006_glb_mutex_2);
		}
	}
#if defined PRINT_DEBUG
	printf("" Task6_2 !Cross thread stack access, thread # % ld !aa = % d\n "", ip);
#endif /* defined(PRINT_DEBUG) */

#endif /* defined(CHECKER_POLYSPACE) */
	return NULL;
}

void st_cross_thread_access_006()
{
	int thread_set = 0;
#if !defined(CHECKER_POLYSPACE)
	pthread_t th1, th2;
	intptr_t t1 = 10;
	intptr_t t2 = 20;
	if (thread_set == CREATE_THREAD)
	{
		;
	}
	else
	{
		pthread_create(&th1, NULL, st_cross_thread_access_006_tsk_001, (void *)t1);
		pthread_create(&th2, NULL, st_cross_thread_access_006_tsk_002, (void *)t2);
		sleep(1);
	}

#endif /* defined(CHECKER_POLYSPACE) */
}
"
