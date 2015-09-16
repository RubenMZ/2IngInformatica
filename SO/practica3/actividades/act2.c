#include<pthread.h>
#include<stdio.h>
#include<stdlib.h>

pthread_mutex_t cerrojo;


void * escribir(void * args);


int main(int argc, char* argv[]){

	if(argc!=2){
		printf("\nERROR ARGUMENTOS. <ejecutable><numero de hebras>\n\n");
		exit(-1);
	}

	long numHebras= atoi(argv[1]);
	char *caracter;
	int i, fail;

	caracter= (char*) malloc(sizeof(char)*numHebras);

	pthread_t * hebras;
	hebras = (pthread_t*) malloc(sizeof(pthread_t)*numHebras);

	for(i=0; i<numHebras;i++){
		printf("Introduce el caracter para imprimir\n");
		scanf("%c", &caracter[i]);
		getchar();
	}

	for(i=0; i<numHebras;i++){
		fail=pthread_create(&hebras[i], NULL, (void*)escribir, (void**)&caracter[i]);
		if(fail!=0){
			printf("Fallo en la hebra %d\n", i);
			exit(-1);
		}
	}

	for(i=0; i<numHebras;i++){
		fail=pthread_join(hebras[i], NULL);
		if(fail!=0){
			printf("Fallo en la hebra %d\n", i);
			exit(-1);
		}
	}


	pthread_exit(NULL);
}


void * escribir(void * args){

	char caracter = *(char*)args;
	int fail, i;

	fail=pthread_mutex_lock(&cerrojo);
	if (fail != 0)
		printf("mutex_lock error...\n");

	for(i=0; i<5; i++){
		printf("%c", caracter);
		fflush(stdout);
		sleep(1);
	}

	fail=pthread_mutex_unlock(&cerrojo);
	if (fail != 0)
		printf("mutex_unlock error...\n");

	pthread_exit(NULL);
}