/*******************************************
Ejemplo de productor-consumidor
Modified from Michael Kerrisk's code, 2014.
********************************************/
#include <pthread.h>
#include <stdlib.h>
#include <stdio.h>
typedef enum {FALSE=0, TRUE=1} booleano;
pthread_mutex_t mtx = PTHREAD_MUTEX_INITIALIZER;
int avail = 0;
static void * threadFunc(void *arg)
{
int cnt = atoi((char *) arg);
int s, j;
for (j = 0; j < cnt; j++)
{
//Lock the mutex
s = pthread_mutex_lock(&mtx);
if (s != 0)
printf("mutex_lock error...\n");
/* Let consumer know another unit is available */ /*Critical section*/
avail++;
printf("avail variable increased by thread %ld, avail=%d\n", (unsigned long) pthread_self(),avail);
//Unlock mutex
s = pthread_mutex_unlock(&mtx);
if (s != 0)
printf("mutex_unlock error...\n");
}
return NULL;
}
int main(int argc, char *argv[])
{
if(argc<=3)
{
printf("Ussage: ./a.out Number_of_increasing_for_threadN\n");
exit(EXIT_FAILURE);
}
pthread_t tid;
int s, j;
int totRequired;
int numConsumed;
booleano done;
//Number_of_increasing_for_thread1
//Number_of_increasing_for_thread2
/* Total number of units that all threads will produce */
/* Total units so far consumed */
/* Create all threads */
totRequired = 0;
for (j = 1; j < argc; j++)
{
totRequired += atoi(argv[j]); //Sum is the total of increments
s = pthread_create(&tid, NULL, threadFunc, argv[j]);
if (s != 0)
printf("pthread_create error...\n");
}
/* Use a polling loop to check for available units */
numConsumed = 0;
done = FALSE;
for (;;) //Continuous simulation
{
//Lock mutex
s = pthread_mutex_lock(&mtx);
if (s != 0)
printf("mutex_lock error...\n");
while (avail > 0) /* Consume all available units */
{
/* Do something with produced unit */
numConsumed ++;
avail--;
printf("Main, numConsumed=%d\n", numConsumed);
//Equivalent to if((numConsumed >= totRequired)==true) done=true else done=false
done = numConsumed >= totRequired;
}
printf("Unproductive time..., avail is <= 0\n");
s = pthread_mutex_unlock(&mtx); /*Desbloqueo de la barrera*/
if (s != 0)
printf("mutex_unlock error...\n");
if (done)
{
printf("Exiting...All produced items have been consumed\n");
break;
}
/* Perhaps do other work here that does not require mutex lock */
}
exit(EXIT_SUCCESS);
}

