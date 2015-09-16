#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#define TOTAL 10

//pthread_cond_t vacio, lleno;
pthread_mutex_t lock;

int array[TOTAL];
int n_elementos=0;

void * productor();
void * consumidor();




int main(int argc, char ** argv){

srand(time(NULL));
int i;
			//Incializamos los cerrojos
		pthread_mutex_init(&lock, NULL);

			//Inicializamos las variables de condicion
		//pthread_cond_init(&vacio, NULL);
		//pthread_cond_init(&lleno, NULL);


pthread_t pid[2];

	for(i=0;i<TOTAL;i++){
			array[i] = rand()%5;
			n_elementos++;
		}

	pthread_create(&pid[0], NULL, (void *) productor, NULL);
	pthread_create(&pid[1], NULL, (void *) consumidor, NULL);


	pthread_join(pid[0], NULL);
	pthread_join(pid[1], NULL);

	

	pthread_exit(NULL);
}



void * productor(){

int i, j;

		pthread_mutex_lock(&lock); //Echamos candado
	for(j=0;j<TOTAL;j++){

			i = rand() % 5;

		while(n_elementos==TOTAL){
				printf("Vector lleno\n");
				pthread_mutex_unlock(&lock);
				//pthread_cond_wait(&lleno, &lock);
		}
						array[j]=i;
						n_elementos++;
						printf("PNum elementos es %d\n", n_elementos);
						printf("Producto creado\n");

				

	}

	pthread_mutex_unlock(&lock);
	//pthread_cond_signal(&vacio);

pthread_exit(NULL);

}

void * consumidor(){

int i, j;
int dato;

		pthread_mutex_lock(&lock);//Echamos candado
	for(j=0;j<TOTAL; j++){



			i = rand() % 5;

			
			while(n_elementos==0){
				printf("Vector vacio\n");
				pthread_mutex_unlock(&lock);
				//pthread_cond_wait(&vacio, &lock);
			}

					dato=array[j];
					n_elementos--;
					printf("CNum elementos es %d\n", n_elementos);
					printf("Producto consumido %d\n", dato);

			
	}

	pthread_mutex_unlock(&lock);
	//pthread_cond_signal(&lleno);


pthread_exit(NULL);
}
