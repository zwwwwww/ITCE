/*
From:ITC
bug: 1
Concurrency defects
1.6
Long lock
1.6.2
wait socket
*/
int sleep_lock_002_glb_data = 0;
pthread_mutex_t sleep_lock_002_glb_mutex_;
pthread_mutex_t *sleep_lock_002_glb_mutex = &sleep_lock_002_glb_mutex_;
void *sleep_lock_002_tsk_001(void *pram)
{
	pthread_mutex_lock(sleep_lock_002_glb_mutex);
	sleep_lock_002_glb_data = (sleep_lock_002_glb_data % 100) + 1;
	/*Tool should not detect this line as error*/ /*No Error:Long Sleep */
	pthread_mutex_unlock(sleep_lock_002_glb_mutex);
	return NULL;
}

void sleep_lock_002()
{
	pthread_t tid1;
	pthread_mutex_init(sleep_lock_002_glb_mutex, NULL);
	pthread_create(&tid1, NULL, sleep_lock_002_tsk_001, NULL);
	pthread_join(tid1, NULL);
	pthread_mutex_destroy(sleep_lock_002_glb_mutex);
}

"
