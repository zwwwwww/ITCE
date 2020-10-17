/*
From:ITC
8
Stack related defects 
8.1
Cross thread stack access
8.1.4
Cross thread stack access over multiple functions using 2 threads inside while loop and if condition
*/
#if defined(CHECKER_POLYSPACE)
#define NULL ((void *)0)
int rand(void);
pthread_mutex_t st_cross_thread_access_004_glb_mutex_1 = PTHREAD_MUTEX_INITIALIZER;
pthread_mutex_t st_cross_thread_access_004_glb_mutex_2 = PTHREAD_MUTEX_INITIALIZER;
char *buf1 = "" String1 "";
char *buf2 = "" String2 "";
char **pbuf[2] = {&buf1, &buf2};
void *st_cross_thread_access_004_tsk_001(void *input)
{
#if !defined(CHECKER_POLYSPACE)
	long ip;
	int i = 5;
	ip = (long)input;
	ip = ip * 10;
	char *buf11 = "" String111 "";

	while (i > 0)
	{
		if (ip >= 0)
		{
			pthread_mutex_lock(&st_cross_thread_access_004_glb_mutex_1);
			pbuf[0] = &buf11;
			pthread_mutex_unlock(&st_cross_thread_access_004_glb_mutex_1);
		}
		i--;
	}
#if defined PRINT_DEBUG
	printf("" Task4_1 !Cross thread stack access, thread # % ld !\n "", ip);
#endif /* defined(PRINT_DEBUG) */

#endif /* defined(CHECKER_POLYSPACE) */

	return NULL;
}

void *st_cross_thread_access_004_tsk_002(void *input)
{
#if !defined(CHECKER_POLYSPACE)
	long ip;
	int i = 5;
	ip = (long)input;
	ip = ip * 20;
	while (i > 0)
	{
		if (ip >= 0)
		{
			pthread_mutex_lock(&st_cross_thread_access_004_glb_mutex_2);
			/*strcpy(*pbuf[0],""TEST""); */ /*Tool should not detect this line as error*/ /*No ERROR:Cross thread stack access error*/
			pthread_mutex_unlock(&st_cross_thread_access_004_glb_mutex_2);
		}
		i--;
	}
#if defined PRINT_DEBUG
	printf("" Task4_2 !Cross thread stack access, thread # % ld !\n "", ip);
#endif /* defined(PRINT_DEBUG) */
#endif /* defined(CHECKER_POLYSPACE) */
	return NULL;
}

void st_cross_thread_access_004()
{
#if !defined(CHECKER_POLYSPACE)
	pthread_t th1, th2;
	intptr_t t1 = 10;
	intptr_t t2 = 20;
	pthread_create(&th1, NULL, st_cross_thread_access_004_tsk_001, (void *)t1);
	pthread_create(&th2, NULL, st_cross_thread_access_004_tsk_002, (void *)t2);
	/*pthread_join(th1, NULL);
	   pthread_join(th2, NULL);*/
#endif /* defined(CHECKER_POLYSPACE) */
}
"
