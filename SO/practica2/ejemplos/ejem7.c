#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>
void * message_print (void * ptr)
{
int error = 0;
char *msg;
/* Desconexión del hilo cuando finalice. pthread_self() devuelve el ID de la hebra que invoca
esta función. Se estudiará a continuación. */
error = pthread_detach(pthread_self());
/* Manejar el error */
//...
msg = (char *) ptr;
sleep(5);
printf("THREAD: This is the Message %s\n", msg);
pthread_exit((void *)5);
}



int main(void)
{
int error = 0;
char mess[] = "This is a test";
pthread_t thr;
int *ret;
int aux = 7;
int prueba;
ret = &aux;
error = pthread_create( &thr, NULL, message_print, (void *) mess);
/* Manejar el error */
//...
printf("MAIN: Thread Message: %s\n", mess);
//Este join() al esperar a una hebra detached tiene comportamiento indefinido. Hay que evitar esto.
pthread_join(thr,(void**) &ret);
printf("Este valor no es de la hebra porque es detached y es igual a %d\n",*(int*)ret);
}
