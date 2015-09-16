#include<stdio.h>
#include<pthread.h>
#include<stdlib.h>

void* cuenta(void* fichero);


int main(int argc, char* argv[]){

	if(argc<=1){
		printf("ERROR. Linea argumentos <ejecutable><fich1><fich2>...\n\n");
		exit(-1);
	}

	int nhebras = argc-1;
	int i, s=1;
	pthread_t th[nhebras];
	int linea, suma=0;

	for(i=0; i<nhebras; i++){
		s=pthread_create(&th[i], NULL, (void *) cuenta, (void **)argv[i+1]);
		if(s!=0){
			perror("Error en el create\n");
			exit(-1);
		}
	}

	for(i=0;i<nhebras; i++){
		s=pthread_join(th[i], (void**)&linea);
		if(s!=0){
			perror("Error en el join\n");
			exit(-1);
		}
		printf("Hebra %d con %d lineas\n", i+1, *(int*)linea);
		suma+=*(int*)linea;
	}

	printf("La suma total es %d\n", suma);

	pthread_exit(NULL);
}

void* cuenta(void* fichero){

	FILE * f;
	char * name = (char*) fichero;
	int* lineas = (int*) malloc(sizeof(int));
	char cadena[100];
	*lineas=0;

	if((f=fopen(name, "r"))==0){
		printf("No se pudo abrir el fichero %s\n", name);
		exit(-1);
	}

	while(fgets(cadena, 100, f)!=NULL){
		(*lineas)++;
	}

	pthread_exit((void*)lineas);
}
