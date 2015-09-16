//Includes y defines
#include<stdio.h>
#include<stdlib.h>
#include<pthread.h>

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

	pthread_t escritor1, escritor2, escritor3;
	pthread_t lector1, lector2, lector3, lector4;
	int error;

		//Lanzar hebras escritoras y lectoras

	printf("Creando escritor1\n");
	error = pthread_create(&escritor1, NULL, (void*)Escritor, NULL);

	if(error!=0){
		printf("Error en el create!\n");
	}
	printf("Creando lector1\n");
	error = pthread_create(&lector1, NULL, (void*)Lector, NULL);

	if(error!=0){
		printf("\nError en el create!\n\n");
	}

	printf("Creando escritor2\n");
	error = pthread_create(&escritor2, NULL, (void*)Escritor, NULL);

	if(error!=0){
		printf("\nError en el create!\n\n");
	}

	printf("Creando escritor3\n");
	error = pthread_create(&escritor3, NULL, (void*)Escritor, NULL);

	if(error!=0){
		printf("\nError en el create!\n\n");
	}
	printf("Creando lector2\n");
	error = pthread_create(&lector2, NULL, (void*)Lector, NULL);

	if(error!=0){
		printf("\nError en el create!\n\n");
	}
	printf("Creando lector3\n");
	error = pthread_create(&lector3, NULL, (void*)Lector, NULL);

	if(error!=0){
		printf("\nError en el create!\n\n");
	}
	printf("Creando lector4\n");
	error = pthread_create(&lector4, NULL, (void*)Lector, NULL);

	if(error!=0){
		printf("\nError en el create!\n\n");
	}

		//Esperar las hebras
	
	error = pthread_join(escritor1, NULL);

		if(error!=0){
			printf("\n Error en el join\n\n");
		}
	error = pthread_join(lector1, NULL);

		if(error!=0){
			printf("\n Error en el join\n\n");
		}
	error = pthread_join(escritor2, NULL);

		if(error!=0){
			printf("\n Error en el join\n\n");
		}
	error = pthread_join(lector2, NULL);

		if(error!=0){
			printf("\n Error en el join\n\n");
		}
		//Destruir los semaforos

	error = pthread_mutex_destroy(&mutex);

	if(error!=0){

		printf("\nError en el destroy mutex\n\n");
	}


	error = pthread_mutex_destroy(&mutex_lectores);

	if(error!=0){
		printf("\nError en el destroy mutex_lectores\n\n");
	}

	pthread_exit(NULL);
}

void* Escritor(void* args){ /* codigo del escritor */

	int error;

	//while(1){
		 error = pthread_mutex_lock(&mutex);
			if(error!=0){
				printf("\nError en el lock escritor!\n\n");
			}
		 printf("El escritor va a modificar el dato %d\n", dato);
		 dato = dato + 2; /* modificar el recurso */
		 printf("El escritor ha modificado el dato %d\n", dato);

		 error = pthread_mutex_unlock(&mutex);

			if(error!=0){
				printf("\nError en el unlock escritor\n\n");
			}

	//}

	pthread_exit(NULL);
}


void* Lector(void* args){ /* codigo del lector */


	int error;

   //while(1){
	error = pthread_mutex_lock(&mutex_lectores);

		if(error!=0){
			printf("\nError en el lock mutex lector\n\n");
		}

	  n_lectores++;
	  if(n_lectores == 1){
		   error = pthread_mutex_lock(&mutex);
			if(error!=0){
				printf("\nError en el lock mutex lector\n\n");
			}

	  }

	error = pthread_mutex_unlock(&mutex_lectores);

		if(error!=0){
			printf("\nError en el unlock mutex lector\n\n");
		}

	printf("EL lector ha leido el dato %d\n", dato); /* leer dato */
	error = pthread_mutex_lock(&mutex_lectores);

		if(error!=0){
			printf("\nError en el lock mutex_lectores lector\n\n");
		}

	  n_lectores--;
	  if(n_lectores == 0){
		   error = pthread_mutex_unlock(&mutex);
			if(error!=0){
				printf("\nError en el unlock mutex lector\n\n");
			}

      }
    error = pthread_mutex_unlock(&mutex_lectores);
    	if(error!=0){
			printf("\nError en el unlock mutex_lectores lector\n\n");
		}

	//}

	pthread_exit(NULL);
}
