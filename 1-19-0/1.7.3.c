/*
From:ITC
bug: 1
Concurrency defects
1.7
Race condition
1.7.3
3 threads access the same resources
*/
void *mythread(void *data);

/* Initialize a mutex */
pthread_mutex_t count_mutex = PTHREAD_MUTEX_INITIALIZER;

/* Global variable which will be shared */
int x = 0;

void race_condition_003()
{

	int i;
	pthread_t pth[10];

	for (i = 0; i < 10; i++)
		pthread_create(&pth[i], NULL, mythread, NULL);

	for (i = 0; i < 10; i++)
		pthread_join(pth[i], NULL);
}

void *mythread(void *data)
{
	pthread_mutex_lock(&count_mutex);

	while (x < 100)
	{

		x++; /*Tool should not detect this line as error*/ /*No ERROR:Race condition*/
	}

	pthread_mutex_unlock(&count_mutex);
	return NULL;
}
