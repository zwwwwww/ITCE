/*
From:ITC
bug: 1
Concurrency defects
1.3
Double release
        1.3.2
Unlock without locking
*/
int rand(void);
pthread_mutex_t double_release_002_glb_mutex_;
pthread_mutex_t *double_release_002_glb_mutex = &double_release_002_glb_mutex_;
void double_release_002_glb_mutex_lock() {}
void double_release_002_glb_mutex_unlock() {}
int double_release_002_glb_data = 0;
void *double_release_002_tsk_001(void *pram)
{
    double_release_002_glb_data = (double_release_002_glb_data % 100) + 1;
    pthread_mutex_unlock(double_release_002_glb_mutex);
    return NULL;
}
void *double_release_002_tsk_002(void *pram)
{
    double_release_002_glb_data = (double_release_002_glb_data % 100) + 1;
    pthread_mutex_unlock(double_release_002_glb_mutex);
    return NULL;
}
void double_release_002()
{
    pthread_t tid1, tid2;
    pthread_mutex_init(double_release_002_glb_mutex, NULL);
    pthread_create(&tid1, NULL, double_release_002_tsk_001, NULL);
    pthread_create(&tid2, NULL, double_release_002_tsk_002, NULL);
    pthread_join(tid1, NULL);
    pthread_join(tid2, NULL);
    pthread_mutex_destroy(double_release_002_glb_mutex);
}
void double_release_002_tskentry_001()
{
    while (1)
    {
        if (rand())
        {
            double_release_002_tsk_001(NULL);
        }
    }
}
