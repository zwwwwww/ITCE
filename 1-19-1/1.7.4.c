/*
From:ITC
bug: 1
Concurrency defects
1.7
Race condition
1.7.4
10 threads access the same resources
*/
void *mythread(void *data);

/* Global variable which will be shared */
int x = 0;

void race_condition_004()
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
	while (x < 100)
	{

		x++; /*Tool should detect this line as error*/ /*ERROR:Race condition*/
	}
	return (NULL);
}
