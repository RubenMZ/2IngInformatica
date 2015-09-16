#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>


long final;

void * fhebras(void* arg);

long main(long argc, char* argv[]){

	if(argc!=2){
		printf("Error de argumentos: <ejecutable><numero de hilos menos de 10>");
		exit(-1);
	}

	long vector[10];
	long i,j, hebras, fail1=0, fail2=0;
	srand(time(NULL));
	long* resultado;
	long total=0;
	long elementos=0;



	hebras = atoi(argv[1]);

	pthread_t* th=(pthread_t*)malloc(sizeof(pthread_t)*hebras);


	for(i=0; i<10; i++){
		vector[i]= rand()%10;
		elementos+=vector[i];
		printf("< %ld >", vector[i]);
	}

	printf("\n\n");

	for(i=0; i<10; i++){


		fail1=pthread_create(&th[i%hebras], NULL, (void*)fhebras, (void**)&vector[i]);
		 printf ("Soy el hilo %ld y tengo el número %ld\n", i%(hebras)+1, vector[i]);

		sleep(1);

		if(fail1!=0){
			perror("Error en el create\n");
			exit(-1);
		}


		if(((i%hebras)==(hebras-1))&&(i!=0)){

			for(j=0; j<hebras; j++){

				fail2 = pthread_join(th[j], (void**)&resultado);

				if(fail2!=0){
				perror("Error en el join\n");
				exit(-1);
				}

					printf("Suma de la hebra %ld: %ld\n", j+1,*(long*)resultado);

				total+=*(long*)resultado;


			}


		}

	}

	for(i=0; i<10%hebras; i++){

				fail2 = pthread_join(th[i], (void**)&resultado);
				if(fail2!=0){
					perror("Error en el join2\n");
					exit(-1);
				}
					printf("Suma de la hebra %ld: %ld\n", i+1,*(long*)resultado);
				total+=*(long*)resultado;

	}

	printf("Suma total: %ld => %ld\n",total, elementos);
	pthread_exit(NULL);
}

void * fhebras(void* arg){

	long* suma = (long*) malloc(sizeof(long));
	long* num = (long*) malloc(sizeof(long));
	fflush(stdout);
	num=(long*)arg;


	*suma+=*num;

	pthread_exit((void*)suma);
}
