/*
From:ITC
bug: 1
Concurrency defects
1.7
Race condition
1.7.1
2 threads access and change the same resources
*/
int race_glb_1 = 5;
int race_glb_2 = 3;

void *race_condition_001_1()
{
	race_glb_1 = 2 * race_glb_1; /*Tool should detect this line as error*/ /*ERROR:Race condition*/
	return NULL;
}

void *race_condition_001_2()
{
	race_glb_1 = 2 + race_glb_1;
	return NULL;
}

void race_condition_001()
{
	pthread_t pthread1, pthread2, pthread3, pthread4;
	pthread_create(&pthread1, NULL, race_condition_001_1, NULL);
	pthread_create(&pthread2, NULL, race_condition_001_1, NULL);
	pthread_create(&pthread3, NULL, race_condition_001_2, NULL);
	pthread_create(&pthread4, NULL, race_condition_001_2, NULL);
}
