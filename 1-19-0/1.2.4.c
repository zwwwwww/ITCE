/*
From:ITC
bug: 1
Concurrency defects
1.2
Double lock
 1.2.4
multiple functions 2 threads
*/
pthread_mutex_t double_lock_004_glb_mutex1 = PTHREAD_MUTEX_INITIALIZER;

void *
Thread3(void *input)
{
#if !defined(CHECKER_POLYSPACE)
   long ip;

   pthread_mutex_lock(&double_lock_004_glb_mutex1);

   ip = (long)input;
   ip = ip * 10;
   printf("Task3! It's me, thread #%lu!\n", ip);
   pthread_mutex_unlock(&double_lock_004_glb_mutex1);
#endif /* defined(CHECKER_POLYSPACE) */

   return NULL;
}
void *Thread4(void *input)
{
#if !defined(CHECKER_POLYSPACE)
   long ip;

   pthread_mutex_lock(&double_lock_004_glb_mutex1); /*Tool should not detect this line as error*/ /*No ERROR:Double Lock*/
   ip = (long)input;
   ip = ip * 10;
   printf("Task4! It's me, thread #%lu!\n", ip);
   pthread_mutex_unlock(&double_lock_004_glb_mutex1);
#endif /* defined(CHECKER_POLYSPACE) */
   return NULL;
}
void double_lock_004()
{
#if !defined(CHECKER_POLYSPACE)
   pthread_t th1, th2;
   long int t1 = 10;
   long int t2 = 20;
   sink += pthread_create(&th1, NULL, Thread3, (void *)t1);
   sink += pthread_create(&th2, NULL, Thread4, (void *)t2);
#endif /* defined(CHECKER_POLYSPACE) */
}
