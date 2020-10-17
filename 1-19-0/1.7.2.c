/*
From:ITC
bug: 1
Concurrency defects
1.7
Race condition
 1.7.2
2 threads access the same resource
*/
int race_condition_002_gbl = 0;
pthread_mutex_t mutex_count;

void *race_condition_002_1()
{
	while (1)
	{
		pthread_mutex_lock(&mutex_count);

		if (race_condition_002_gbl < 100)
		{
			race_condition_002_gbl++; /*Tool should not detect this line as error*/ /*No ERROR:Race condition*/
		}

		pthread_mutex_unlock(&mutex_count);
		break;
	}
	return NULL;
}

void race_condition_002()
{
	while (1)
	{
		pthread_t pthread1, pthread2;

		pthread_create(&pthread1, NULL, race_condition_002_1, NULL);
		pthread_create(&pthread2, NULL, race_condition_002_1, NULL);

		pthread_join(pthread1, NULL);
		pthread_join(pthread2, NULL);
		break;
	}
}
