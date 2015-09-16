#include <stdio.h>
#include <stdlib.h>
#include <pthread.h> 

void * funcion(void* value);


int main(){

	pthread_t th1, th2;
	char cad1[]="Hola ", cad2[]="mundo";


	pthread_create(&th1, NULL, (void*) funcion, (void*)cad1);
	sleep(5);
	pthread_create(&th2, NULL, (void*) funcion, (void*)cad2);

	pthread_join(th1, NULL);
	pthread_join(th2, NULL);



	pthread_exit(NULL);	
}

void* funcion(void* value){

	char * cadena = malloc(sizeof(char)*50);
	cadena=(char*) value;
	int i=0;
	
	while(cadena[i]!='\0'){
		printf("%c", cadena[i]);
		sleep(1);
		fflush(stdout);
		i++;
	}
		

	pthread_exit(NULL);

}
