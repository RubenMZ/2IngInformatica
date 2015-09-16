#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
//Prototipo
void *mifuncion (void *arg);
void miFuncion2 (void);



void main (void)
{
pthread_t tid;
int misargs[2];
misargs[0] = -5;
misargs[1] = -6;
printf("Se va a crear un hilo...\n");
pthread_create(&tid, NULL, mifuncion, (void *) misargs);
printf("Hilo creado. Esperando su finalizacion con pthread_join()...\n");
/*Si comentamos la siguiente linea, puede que a la hebra no le de tiempo a ejecutarse ni siquiera parcialmente,
de manera que el main() terminará y con el todas las hebras asociadas a este proceso*/
pthread_join(tid, NULL);
printf("Proceso principal finalizado...\n");
exit(EXIT_SUCCESS);
}


void *mifuncion(void *arg)
{
int *argu;
printf("Hilo hijo ejecutando...\n");
argu = (int *) arg; //Casting a entero del parámetro de entrada.

printf("Hilo hijo: arg1= %d arg2= %d\n", argu[0], argu[1]);
printf("Hilo hijo finalizando....\n");
miFuncion2();
/*No se llegará a ejecutar de aquí hasta el final de esta función*/
sleep(2);
printf("Soy el hilo. He salido de la llamada a subrutina\n");
pthread_exit(NULL);
}


void miFuncion2()
{
printf("Soy el hilo y estoy dentro de una subrutina. Invocando a pthread_exit()\n");
pthread_exit(NULL);
}
