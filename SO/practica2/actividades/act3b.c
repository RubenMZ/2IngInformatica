#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>



typedef struct param{

	long * v;
	int inicial;
	int final;

}param;

void * fhebras(void* arg);

long main(long argc, char* argv[]){

	if(argc!=2){
		printf("Error de argumentos: <ejecutable><numero de hilos menos de 10>");
		exit(-1);
	}


	long hebras = atoi(argv[1]);

	long vectorNum[10];
	int i, j;
	long fail1=0, fail2=0, inicio=0, final=0, elemporhebra, resto;
	srand(time(NULL));
	void* resultado;
	long total=0;
	long elementos=0;
	param* vectorHeb = (param*) malloc(sizeof(param)*hebras);


	resto=10%hebras;
	elemporhebra=10/hebras;

	printf("Vector de numero aletorios: \n\n");

	for(i=0; i<10; i++){
		vectorNum[i]= rand()%10;
		elementos+=vectorNum[i];
		printf("< %ld >", vectorNum[i]);
	}

	printf("\nCreando division por hebras de %ld\n", hebras);

	for(i=0;i<hebras; i++){

		if(i!=0){
			inicio=final + 1;
		}else{
			inicio=0;
		}

		final=inicio + (10/hebras) - 1;

		if(resto!=0){
			final++;
			resto--;
		}

		vectorHeb[i].inicial=inicio;
		vectorHeb[i].final=final;
		vectorHeb[i].v= vectorNum;	

	}

	printf("Creada la division y ejecutando hebras\n");

	pthread_t* th=(pthread_t*)malloc(sizeof(pthread_t)*hebras);

	for(i=0;i<hebras; i++){

		fail1=pthread_create(&th[i], NULL, (void*)fhebras, (void**)&vectorHeb[i]);
		if(fail1!=0){
			printf("Error en el create de la hebra %d\n",i+1);
			exit(-1);
		}
		printf("Creada hebra num %d\n", i+1);

	}

	printf("\nRecogiendo hebras\n");

	for(i=0;i<hebras; i++){

		fail2=pthread_join(th[i], (void**)&resultado);
		if(fail2!=0){
			printf("Error en el create de la hebra %d\n",i+1);
			exit(-1);
		}
		total+= *(long*)resultado;
		printf("Subsuma de la hebra %d es = %ld\n", i+1, *(long*)resultado);
	}

	printf("Suma total: %ld => %ld\n",total, elementos);
	pthread_exit(NULL);
}

void * fhebras(void* arg){

	long* suma = (long*) malloc(sizeof(long));
	struct param* aux = (struct param*)malloc(sizeof(struct param));
	aux= (struct param*) arg;
	int i;	

	for(i=(*aux).inicial ; i<=(*aux).final; i++){
		*suma+= aux->v[i];
	}

	pthread_exit((void*)suma);
}
