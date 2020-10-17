/*
From:ITC
bug: 1
Concurrency defects
1.8
Unlock without lock
1.8.3
multiple functions two threads
*/
int rand();
pthread_mutex_t unlock_without_lock_003_glb_mutex = PTHREAD_MUTEX_INITIALIZER;
#if defined(CHECKER_POLYSPACE)
void unlock_without_lock_003_glb_mutex_lock()
{
}
void unlock_without_lock_003_glb_mutex_unlock() {}
#endif /* #if defined(CHECKER_POLYSPACE) */
float unlock_without_lock_003_glb_data = 1000.0;
int unlock_without_lock_003_func_002(int a);
void unlock_without_lock_003_func_001(void *pram)
{
#if !defined(CHECKER_POLYSPACE)
  if (unlock_without_lock_003_func_002(10) > 1)
  {
    pthread_mutex_lock(&unlock_without_lock_003_glb_mutex); /*Tool should not detect this line as error*/ /* No ERROR:UnLock without lock */
  }
  unlock_without_lock_003_glb_data = (unlock_without_lock_003_glb_data) + 1.2;

#if defined PRINT_DEBUG
  int ip = (intptr_t)pram;
  printf(" Task3 !Unlock without Lock, thread # % d !gbl3 = % f \n ", ip, unlock_without_lock_003_glb_data);
#endif /* defined(PRINT_DEBUG) */
  unlock_without_lock_003_func_002(10);
  if (unlock_without_lock_003_func_002(10) > 1)
  {
    pthread_mutex_unlock(&unlock_without_lock_003_glb_mutex);
  }
#endif /* ! defined(CHECKER_POLYSPACE) */
}

int unlock_without_lock_003_func_002(int a)
{
  int ret = 0;
  if (a > 1)
  {
    ret = a++;
  }
  else
  {
    ret = 0;
  }
  return ret;
}

void *unlock_without_lock_003_tsk_001(void *pram)
{
#if !defined(CHECKER_POLYSPACE)

  if (unlock_without_lock_003_func_002(10) > 1)
  {
    pthread_mutex_lock(&unlock_without_lock_003_glb_mutex);
  }
  unlock_without_lock_003_glb_data = (unlock_without_lock_003_glb_data) + 3.5;
  // JDR: commenting out next line which deadlocks us due to taking a lock twice
  // unlock_without_lock_003_func_001(pram);
  if (unlock_without_lock_003_func_002(10) > 1)
  {
    pthread_mutex_unlock(&unlock_without_lock_003_glb_mutex);
  }
#endif /* defined(CHECKER_POLYSPACE) */
  return NULL;
}

void unlock_without_lock_003()
{
#if !defined(CHECKER_POLYSPACE)
  pthread_t tid1, tid2;
  intptr_t t1 = 10, t2 = 20;
  pthread_mutex_init(&unlock_without_lock_003_glb_mutex, NULL);
  pthread_create(&tid1, NULL, unlock_without_lock_003_tsk_001, (void *)t1);
  pthread_create(&tid2, NULL, unlock_without_lock_003_tsk_001, (void *)t2);
  pthread_join(tid1, NULL);
  pthread_join(tid2, NULL);
  pthread_mutex_destroy(&unlock_without_lock_003_glb_mutex);
#endif /* defined(CHECKER_POLYSPACE) */
}

#if defined(CHECKER_POLYSPACE)
void unlock_without_lock_003_tskentry_001()
{
  while (1)
  {
    if (rand())
    {
      unlock_without_lock_003_tsk_001(NULL);
    }
  }
}
#endif /* defined(CHECKER_POLYSPACE) */ "
