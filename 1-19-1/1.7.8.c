/*
From:ITC
bug: 1
Concurrency defects
1.7
Race condition
1.7.8

*/
pthread_mutex_t race_condition_008_glb_mutex_1 = PTHREAD_MUTEX_INITIALIZER;
pthread_mutex_t race_condition_008_glb_mutex_2 = PTHREAD_MUTEX_INITIALIZER;
float race_condition_008_glb_data = 1000.0;
void *race_condition_008_tsk_001(void *input)
{
#if !defined(CHECKER_POLYSPACE)
   long ip;
   /*pthread_mutex_lock( &race_condition_008_glb_mutex_1 );*/
   ip = (long)input;
   ip = ip * 10;
   race_condition_008_glb_data++; /*Tool should detect this line as error*/ /*ERROR:Race condition*/
#if defined PRINT_DEBUG
   printf(" Task4_1 !race condition, thread # % ld !\n ", ip);
#endif /* defined(PRINT_DEBUG) */

   /*pthread_mutex_unlock( &race_condition_008_glb_mutex_1 );*/
#endif /* defined(CHECKER_POLYSPACE) */

   return NULL;
}

void *race_condition_008_tsk_002(void *input)
{
#if !defined(CHECKER_POLYSPACE)
   long ip;

   /*pthread_mutex_lock( &race_condition_008_glb_mutex_2 );*/
   ip = (long)input;
   ip = ip * 20;
   race_condition_008_glb_data--;
#if defined PRINT_DEBUG
   printf(" Task4_2 !race condition, thread # % ld !\n ", ip);
#endif /* defined(PRINT_DEBUG) */
   /*pthread_mutex_unlock( &race_condition_008_glb_mutex_2 );*/
#endif /* defined(CHECKER_POLYSPACE) */
   return NULL;
}
void race_condition_008()
{
#if !defined(CHECKER_POLYSPACE)
   pthread_t th1, th2;
   intptr_t t1 = 10;
   intptr_t t2 = 20;
   pthread_create(&th1, NULL, race_condition_008_tsk_001, (void *)t1);
   pthread_create(&th2, NULL, race_condition_008_tsk_002, (void *)t2);
   sleep(1);
#endif /* defined(CHECKER_POLYSPACE) */
}
