#include <stdio.h>
#include <pthread.h>
#include <stdlib.h>
#include <string.h>

char buffer[1024];
int leidos=0;
int nLectores=0;
int copias;
int FIN=0;


pthread_mutex_t mutex, mutex_lectores;
pthread_cond_t vacio, lleno;

void* lector(void * args);
void* escritor(void * args);

int main(int argc, char * argv[]){

	if(argc!=3){
		printf("\nERROR. Mal argumentos <%s> <fichero> <numero de copias>\n\n", argv[0]);
		exit(-1);
	}

	FILE* f;
	copias=atoi(argv[2]);
	int i;
	char fichero[50], auxFichero[50][50], auxFichero2[50][50];
	char* c = (char*)malloc(sizeof(char));
	strcpy(fichero, argv[1]);
	pthread_t * hebras = (pthread_t*) malloc ((copias+1)*sizeof(pthread_t));
	int error;

	/*SE CREAN LOS FICHEROS COPIAS*/
		error=pthread_create(&hebras[0], NULL, (void*)lector, (void*)fichero);
		if(error!=0){
			printf("\nError en el create de la hebra lectora\n\n");
			exit(-1);
		}


	for(i=0; i<copias;i++){
		*c=(char)i;

		strncat(auxFichero[i], fichero, strlen(fichero)-strlen((rindex(fichero,'.'))));
		sprintf(auxFichero2[i],"%s%d%s", auxFichero[i], i, ".txt");

		error = pthread_create(&hebras[i+1], NULL, (void*)escritor, (void*)auxFichero2[i]);

		if(error!=0){
			printf("\nError en el create de la hebra escritora %d\n\n", i+1);
			exit(-1);
		}
		/*if((f=fopen(auxFichero2[i], "w"))==NULL)
			printf("ERROR. al crear fichero para copia n. %d\n", i);

		fclose(f);*/
		//strcpy(fichero, argv[1]);
		//strcpy(auxFichero, "");
	}


		for(i=0;i<(copias+1);i++){
			//error=pthread_join(hebras[i], NULL);
			if(error!=0){
				printf("\nError en el join de la hebra %d\n\n", i);
				exit(-1);
			}
		}




	pthread_exit(NULL);
}

/***********************************************************************************************

											
											LECTOR


***********************************************************************************************/



void* lector(void * args){

	FILE* f;
	char * fileName = (char* ) malloc (sizeof(char)*500);
	fileName = (char * )args;
	char caracter;
	int error;

	do{

			error = pthread_mutex_lock(&mutex);
			if(error!=0){
				printf("\nError en el lock mutex\n\n");
			}

			printf("filename LECTOR: %s\n", fileName);

			while(leidos!=0){
				printf("El buffer esta lleno\n");
				error = pthread_cond_wait(&vacio, &mutex);
				if(error!=0){
					printf("\nError en el wait vacio\n\n");
				}
			}

				if((f=fopen(fileName, "r"))==NULL){
					printf("Error al abrir el fichero <%s>\n",fileName);
					exit(-1);
				}

				printf("Leyendo fichero......\n");
				fflush(stdout);

			while( ((caracter=fgetc(f))!=EOF) && (leidos!=1024)){

				buffer[leidos]=caracter;
				leidos++;

			}

			if(fgetc(f)==EOF){
				FIN=1;
			}

				fclose(f);

			error = pthread_cond_signal(&lleno);
			if(error!=0){
				printf("\nError en el signal lleno\n\n");
			}

			error = pthread_mutex_unlock(&mutex);
			if(error!=0){
				printf("\nError en el unlock mutex\n\n");
			}

	}while(FIN==0);

	pthread_exit(NULL);
}

/***********************************************************************************************

											
											ESCRITOR


***********************************************************************************************/

void* escritor(void * args){

	FILE* f;
	char * fileName = (char* ) malloc (sizeof(char)*500);
	fileName = (char * )args;
	int i, error;

		do{

		error = pthread_mutex_lock(&mutex);
		while(error!=0){
			printf("\nError en el lock mutex\n\n");
		}

		printf("filename ESCRITOR: %s\n", fileName);

		if(leidos==0){
			printf("El buffer esta vacio\n");
			error = pthread_cond_wait(&lleno, &mutex);
			if(error!=0){
				printf("\nError en el wait vacio\n\n");
			}
		}
		

		if((f=fopen(fileName, "a"))==NULL){
			printf("Error al abrir el fichero <%s>\n", fileName);
			exit(-1);
		}

					printf("Escribiendo fichero......\n");
					fflush(stdout);

		nLectores++;
		for(i=0;i<leidos;i++){
			fprintf(f, "%c", buffer[i]);
		}

		fclose(f);


		if(nLectores==copias){

			nLectores=0;
			leidos=0;

			error = pthread_cond_signal(&vacio);
			if(error!=0){
				printf("\nError en el signal lleno\n\n");
			}
		}

		error = pthread_mutex_unlock(&mutex);
		if(error!=0){
			printf("\nError en el unlock mutex\n\n");
		}

		if((leidos==0) && (nLectores==0) && FIN ==0){

			printf("El buffer esta vacio, esperando al lector\n");
			error = pthread_cond_wait(&lleno, &mutex);
			if(error!=0){
				printf("\nError en el wait vacio\n\n");
			}
		}


	}while(leidos!=0);

	pthread_exit(NULL);
}