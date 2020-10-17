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
void *race_condition_002_1()
{
	while (1)
	{
		if (race_condition_002_gbl < 100)
		{
			race_condition_002_gbl++;
		}
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
	}
}
