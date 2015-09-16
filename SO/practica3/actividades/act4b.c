//Includes y defines
#include<stdio.h>
#include<stdlib.h>
#include<pthread.h>
#include<time.h>

//Seccion critica
int dato = 4; /* Puede ser cualquier otro tipo de recurso */
int n_lectores = 0; /* numero de lectores */
pthread_mutex_t mutex; /* controlar el acceso a dato */
pthread_mutex_t mutex_lectores; /* controla la variable n_lectores */

void* Lector(void* args);
void* Escritor(void* args);


int main(){

	pthread_mutex_init(&mutex, NULL);
	pthread_mutex_init(&mutex_lectores, NULL);

		//Iniciar hebras escritoras y lectoras

	//pthread_t escritor1, escritor2, escritor3;
	//pthread_t lector1, lector2, lector3, lector4;

	pthread_t escritor[10];
	pthread_t lector[10];
	srand(time(NULL));

	int i;

		//Lanzar hebras escritoras y lectoras
/*
	printf("Creando escritor1\n");
	pthread_create(&escritor1, NULL, (void*)Escritor, NULL);

	printf("Creando lector1\n");
	pthread_create(&lector1, NULL, (void*)Lector, NULL);

	printf("Creando escritor2\n");
	pthread_create(&escritor2, NULL, (void*)Escritor, NULL);

	printf("Creando escritor3\n");
	pthread_create(&escritor3, NULL, (void*)Escritor, NULL);

	printf("Creando lector2\n");
	pthread_create(&lector2, NULL, (void*)Lector, NULL);


	printf("Creando lector3\n");
	pthread_create(&lector3, NULL, (void*)Lector, NULL);

	printf("Creando lector4\n");
	pthread_create(&lector4, NULL, (void*)Lector, NULL);
*/

	for(i=0;i<3; i++){
			printf("Creando escritor %d\n", i+1);
			pthread_create(&escritor[i], NULL, (void*)Escritor, NULL);
			printf("Creando lector %d\n", i+1);
			pthread_create(&lector[i], NULL, (void*)Lector, NULL);			
	}

		//Esperar las hebras
/*	
	pthread_join(escritor1, NULL);
	pthread_join(lector1, NULL);
	pthread_join(escritor2, NULL);
	pthread_join(escritor3, NULL);
	pthread_join(lector2, NULL);
	pthread_join(lector3, NULL);
	pthread_join(lector4, NULL);

*/

	for(i=0;i<3; i++){

	pthread_join(escritor[i], NULL);
	pthread_join(lector[i], NULL);
	
	}

		//Destruir los semaforos

	pthread_mutex_destroy(&mutex);
	pthread_mutex_destroy(&mutex_lectores);

	pthread_exit(NULL);
}

void* Escritor(void* args){ /* codigo del escritor */

	//while(1){
		 FILE* f;

		 

		 pthread_mutex_lock(&mutex);

		 if((f=fopen("ficheroAct4.txt", "a"))==NULL){
			printf("ERROR. Al abrir el fichero para escribir.\n\n");
			exit(-1);
		 }

		 printf("El escritor va a modificar el dato %d\n", dato);
		 
		 fprintf(f, "Escribo con dato %d \n", dato); /* modificar el recurso */
		 dato=dato+2;
		 printf("El escritor ha modificado el dato %d\n", dato);
		 fclose(f);
		 pthread_mutex_unlock(&mutex);
	//}

	pthread_exit(NULL);
}


void* Lector(void* args){ /* codigo del lector */

	FILE * f;
	char c;

   //while(1){
	pthread_mutex_lock(&mutex_lectores);
	  n_lectores++;
	  if(n_lectores == 1){
		   pthread_mutex_lock(&mutex);
	  }
	//pthread_mutex_unlock(&mutex_lectores);

		 if((f=fopen("ficheroAct4.txt", "r"))==NULL){
			printf("ERROR. Al abrir el fichero para escribir.\n\n");
			exit(-1);
		 }


		printf("\nEL FICHERO ES ASI:\n\n");

		while((c=fgetc(f))!=EOF){
			printf("%c", c);
			//fflush(stdout);
		}

		printf("\nFIN DEL FICHERO\n\n");

		fclose(f);
	printf("EL lector ha leido el dato %d\n", dato); /* leer dato */
//	pthread_mutex_lock(&mutex_lectores);
	  n_lectores--;
	  if(n_lectores == 0){
		   pthread_mutex_unlock(&mutex);
      }
    pthread_mutex_unlock(&mutex_lectores);
	//}

	pthread_exit(NULL);
}
