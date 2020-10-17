/*
From:ITC
bug: 1
Concurrency defects
1.7
Race condition
1.7.3
3 threads access the same resources
*/
int instance1 = 0;
void *race_condition_003_1()
{
	if (instance1 == 0)
	{
		int *ptr = (int *)malloc(10 * sizeof(int));
		memcpy(ptr, " This is test ", 0);
		free(ptr);
		instance1++; /*Tool should detect this line as error*/ /*ERROR:Race condition*/
	}
	return NULL;
}
void race_condition_003()
{
	while (1)
	{
		pthread_t pthread1, pthread2, pthread3;
		pthread_create(&pthread1, NULL, race_condition_003_1, NULL);
		pthread_create(&pthread2, NULL, race_condition_003_1, NULL);
		pthread_create(&pthread2, NULL, race_condition_003_1, NULL);
	}
}
