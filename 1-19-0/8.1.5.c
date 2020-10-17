/*
From:ITC
8
Stack related defects 
8.1
Cross thread stack access
8.1.5
"Thread created in else condition that will never execute , no lock but there is a unlock"
*/
#if defined(CHECKER_POLYSPACE)
#define NULL ((void *)0)
int rand(void);
pthread_mutex_t st_cross_thread_access_005_glb_mutex = PTHREAD_MUTEX_INITIALIZER;
pthread_mutex_t st_cross_thread_access_005_glb_mutex_1 = PTHREAD_MUTEX_INITIALIZER;
int st_cross_thread_access_005_glb_data = 0;

#define NO_THREAD 0
int st_cross_thread_access_005_thread_set = NO_THREAD;
int arr[4][4] = {{1, 2, 3, 4},
				 {11, 22, 33, 44},
				 {33, 44, 55, 66},
				 {55, 66, 77, 88}};
int (*p)[4] = arr;

void *st_cross_thread_access_005_tsk_001(void *pram)
{
#if !defined(CHECKER_POLYSPACE)
	if (st_cross_thread_access_005_thread_set != NO_THREAD)
	{
		;
	}
	else
	{
		int arr1[4][4] = {{1, 2, 3, 4},
						  {11, 22, 33, 44},
						  {33, 44, 55, 66},
						  {55, 66, 77, 88}};
		p = arr1;
		pthread_mutex_lock(&st_cross_thread_access_005_glb_mutex);
		st_cross_thread_access_005_glb_data = (st_cross_thread_access_005_glb_data % 100) + 5;
		pthread_mutex_unlock(&st_cross_thread_access_005_glb_mutex);

		unsigned long ip = (unsigned long)pthread_self();
		printf("" Task5 !Cross thread stack access, threadID # % lu !gbl5 = % d arrval = % d \n "", ip, st_cross_thread_access_005_glb_data, *(p[2] + 2));

#endif /* defined(CHECKER_POLYSPACE) */
	}
	return NULL;
}

void *st_cross_thread_access_005_tsk_002(void *pram)
{
#if !defined(CHECKER_POLYSPACE)
	if (st_cross_thread_access_005_thread_set != NO_THREAD)
	{
		;
	}
	else
	{
		/**(p[2]+2) =10;*/ /*Tool should not detect this line as error*/ /*No ERROR:Cross thread stack access error*/
		pthread_mutex_lock(&st_cross_thread_access_005_glb_mutex_1);
		st_cross_thread_access_005_glb_data = (st_cross_thread_access_005_glb_data % 100) + 5;
		pthread_mutex_unlock(&st_cross_thread_access_005_glb_mutex_1);

		unsigned long ip = (unsigned long)pthread_self();
		printf("" Task5_2 !Cross thread stack access, threadID # % lu !gbl5 = % d\n "", ip, st_cross_thread_access_005_glb_data);

#endif /* defined(CHECKER_POLYSPACE) */
	}
	return NULL;
}

void st_cross_thread_access_005()
{
#if !defined(CHECKER_POLYSPACE)
	if (st_cross_thread_access_005_thread_set != NO_THREAD)
	{
		;
	}
	else
	{
		pthread_t tid1, tid2;
		pthread_mutex_init(&st_cross_thread_access_005_glb_mutex, NULL);
		pthread_create(&tid1, NULL, st_cross_thread_access_005_tsk_001, NULL);
		sleep(4);
		pthread_mutex_init(&st_cross_thread_access_005_glb_mutex_1, NULL);
		pthread_create(&tid2, NULL, st_cross_thread_access_005_tsk_002, NULL);
		pthread_join(tid1, NULL);
		pthread_join(tid2, NULL);
		pthread_mutex_destroy(&st_cross_thread_access_005_glb_mutex);
		pthread_mutex_destroy(&st_cross_thread_access_005_glb_mutex_1);
	}
#endif /* defined(CHECKER_POLYSPACE) */
}
"
