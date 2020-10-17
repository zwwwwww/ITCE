/*
From:ITC
bug: 1
Concurrency defects
1.3
Double release
1.3.4
inside and outside a loop
*/
int rand(void);
pthread_mutex_t double_release_004_glb_mutex_;
pthread_mutex_t *double_release_004_glb_mutex = &double_release_004_glb_mutex_;

void double_release_004_glb_mutex_lock() {}
void double_release_004_glb_mutex_unlock() {}

int double_release_004_glb_data = 0;

void *double_release_004_tsk_001(void *pram)
{
	int i;
	for (i = 0; i < 2; i++)
	{
		pthread_mutex_lock(double_release_004_glb_mutex);
		double_release_004_glb_data = (double_release_004_glb_data % 100) + 1;
		pthread_mutex_unlock(double_release_004_glb_mutex); /*Tool should not detect this line as error*/ /*No ERROR:Double UnLock*/
	}
	return NULL;
}

void double_release_004()
{
	pthread_t tid1;
	pthread_mutex_init(double_release_004_glb_mutex, NULL);
	pthread_create(&tid1, NULL, double_release_004_tsk_001, NULL);
	pthread_join(tid1, NULL);
	pthread_mutex_destroy(double_release_004_glb_mutex);
}
void double_release_004_tskentry_001()
{
	while (1)
	{
		if (rand())
		{
			double_release_004_tsk_001(NULL);
		}
	}
}
