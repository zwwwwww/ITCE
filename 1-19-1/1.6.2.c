/*
From:ITC
bug: 1
Concurrency defects
1.6
Long lock
1.6.2
wait socket
*/
pthread_mutex_t sleep_lock_002_glb_mutex_;
pthread_mutex_t *sleep_lock_002_glb_mutex = &sleep_lock_002_glb_mutex_;
/* #if defined(CHECKER_POLYSPACE) */
void sleep_lock_002_glb_mutex_lock() {}
void sleep_lock_002_glb_mutex_unlock() {}
/* #endif  #if defined(CHECKER_POLYSPACE) */

char sleep_lock_002_glb_data[256];
int sleep_lock_002_glb_size;

void *sleep_lock_002_tsk_001(void *pram)
{
	int ret;
	int sock;
#ifndef __NO_COVERITY__
	struct sockaddr_in addr;

	sock = socket(AF_INET, SOCK_DGRAM, 0);
	if (sock < 0)
	{
		return NULL;
	}
	memset(&addr, 0, sizeof(addr));
	addr.sin_family = AF_INET;
	addr.sin_port = htons(12345);
	addr.sin_addr.s_addr = INADDR_ANY;
	ret = connect(sock, (struct sockaddr *)&addr, sizeof(addr));
#endif
	if (ret != 0)
	{
		close(sock);
		return NULL;
	}

	/* Lock */
	pthread_mutex_lock(sleep_lock_002_glb_mutex);

	/* Incoming */
#ifndef __NO_COVERITY__

	sleep_lock_002_glb_size =
		recv(sock, sleep_lock_002_glb_data, 256, 0);
	sleep(3600); /*Tool should detect this line as error*/ /*Error:Long Sleep */
#endif

	/* Lock or unlock */
	pthread_mutex_unlock(sleep_lock_002_glb_mutex);

	close(sock);
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
void sleep_lock_002_tskentry_001()
{
	while (1)
	{
		if (rand())
		{
			sleep_lock_002_tsk_001(NULL);
		}
	}
}
