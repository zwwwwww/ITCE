/*
From:ITC
bug: 1
Concurrency defects
1.7
Race condition
1.7.1
2 threads access and change the same resources
*/
pthread_mutex_t glb_1_mutex;
pthread_mutex_t glb_2_mutex;
int race_glb_1 = 5;
int race_glb_2 = 3;

void *race_condition_001_1()
{
	while (1)
	{
		pthread_mutex_lock(&glb_1_mutex);

		if (race_glb_1 == 5)
		{
			race_glb_1++; /*Tool should not detect this line as error*/ /*No ERROR:Race condition*/
		}

		pthread_mutex_unlock(&glb_1_mutex);
		if (race_glb_1 > 50)
		{
			break;
		}
	}
	return NULL;
}

void *race_condition_001_2()
{
	while (1)
	{
		pthread_mutex_lock(&glb_2_mutex);

		race_glb_1 = 2 + race_glb_1;

		pthread_mutex_unlock(&glb_2_mutex);
		if (race_glb_1 > 50)
		{
			break;
		}
	}
	return NULL;
}

void race_condition_001()
{
	pthread_t pthread1, pthread2;

	pthread_mutex_init(&glb_1_mutex, NULL);
	pthread_mutex_init(&glb_2_mutex, NULL);

	pthread_create(&pthread1, NULL, race_condition_001_1, NULL);
	pthread_create(&pthread2, NULL, race_condition_001_2, NULL);

	pthread_join(pthread1, NULL);
	pthread_join(pthread2, NULL);
}
