#include <stdio.h>
#include <pthread.h>
#include <stdlib.h>
#include <semaphore.h>
#include <sys/sem.h>

sem_t male, female;
pthread_cond_t vacio; //variable para comprobar si hay mujeres hombres o esta vacio
pthread_mutex_t candado;
int variable; //0 si esta vacio, 1 si hay hombres y -1 si hay mujeres
int valueHombre, valueMujer;

void* hombre(void* args);
void* mujer(void* args);



int main(int argc, char* argv[]){

	if(argc!=2){
		printf("ERROR de argumentos. <%s> <numero de hebras>\n",argv[0]);
		exit(-1);
	}

	sem_init(&male, 0, 3);
	sem_init(&female, 0, 3);
	pthread_mutex_init(&candado, NULL);
	pthread_cond_init(&vacio, NULL);


	int numHebras = atoi(argv[1]), i;
	pthread_t* hombres, *mujeres;
	hombres = (pthread_t *) malloc (sizeof(pthread_t)*numHebras);
	mujeres = (pthread_t *) malloc (sizeof(pthread_t)*numHebras);

	for(i=0 ; i<numHebras; i++){
		pthread_create(&hombres[i], NULL, (void*)hombre, NULL);
		pthread_create(&mujeres[i], NULL, (void*)mujer, NULL);
	}

	for(i=0 ; i<numHebras; i++){
		pthread_join(hombres[i], NULL);
		pthread_join(mujeres[i], NULL);
	}



	pthread_exit(NULL);
}


void* hombre(void* args){


	pthread_mutex_lock(&candado);

		while(variable==-1){
			printf("Hay mujeres en WC\n");
			pthread_cond_wait(&vacio, &candado);
		}

		variable=1;

	pthread_mutex_unlock(&candado);

	sem_wait(&male);
	printf("-> entra hombre\n");

	sleep(2);


	sem_post(&male);
	printf("<- sale hombre\n");
	

	pthread_mutex_lock(&candado);
	sem_getvalue(&male, &valueHombre);
	if(valueHombre==3){
		variable=0;
		pthread_cond_signal(&vacio);
		printf("Han salido los hombres y el WC esta vacio\n");
	}
	pthread_mutex_unlock(&candado);

	pthread_exit(NULL);
}


void* mujer(void* args){


	pthread_mutex_lock(&candado);

		while(variable==1){
			printf("Hay hombres en WC\n");
			pthread_cond_wait(&vacio, &candado);
		}

		variable=-1;

	pthread_mutex_unlock(&candado);

	sem_wait(&female);
	printf("-> entra mujer\n");

	sleep(2);


	printf("<- sale mujer\n");
	sem_post(&female);


	pthread_mutex_lock(&candado);

	sem_getvalue(&female, &valueMujer);
	if(valueMujer==3){
		variable=0;
		pthread_cond_signal(&vacio);
		printf("Han salido las mujeres y el WC esta vacio\n");
	}
	pthread_mutex_unlock(&candado);


	pthread_exit(NULL);
}
