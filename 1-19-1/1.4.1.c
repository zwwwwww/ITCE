/*
From:ITC
bug: 1
Concurrency defects
1.4
Live lock
1.4.1
livelock
*/
pthread_mutex_t livelock_001_glb_A;
pthread_mutex_t livelock_001_glb_B;

int x, y;

void *mythreadA(void *pram)
{
	while (1)
	{
		pthread_mutex_lock(&livelock_001_glb_A);
		x = x + 1;
		pthread_mutex_unlock(&livelock_001_glb_A);

		int status = pthread_mutex_trylock(&livelock_001_glb_B);
		if (status == 0)
		{
			continue;
		}
	}
	return NULL;
}

void *mythreadB()
{
	while (1)
	{
		pthread_mutex_lock(&livelock_001_glb_B);
		y = y + 1;
		pthread_mutex_unlock(&livelock_001_glb_B);

		int status = pthread_mutex_trylock(&livelock_001_glb_A);
		if (status == 0)
		{
			continue;
		}
	}
	return NULL;
}

void livelock_001()
{
	pthread_t pthreadA, pthreadB;

	pthread_mutex_init(&livelock_001_glb_A, NULL);
	pthread_mutex_init(&livelock_001_glb_B, NULL);

	pthread_create(&pthreadA, NULL, mythreadA, NULL);
	pthread_create(&pthreadB, NULL, (void *)&mythreadB, NULL);

	pthread_join(pthreadA, NULL);
	pthread_join(pthreadB, NULL);
}
