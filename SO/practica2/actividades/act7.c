#include<stdio.h>
#include<pthread.h>
#include<stdlib.h>

struct param{

	int num;
	char cadena[100];
};

void* modificar(void* arg);

int main(){

	int n,i, a, b;

	printf("Ingrese el numero de hebras que desea crear: ");
	scanf("%d", &n);

	pthread_t th[n];
	struct param var[n], *aux;

	for(i=0; i<n; i++){
		printf("Introduce un numero entero mayor que cero: ");
		scanf("%d", &var[i].num);
		getchar();
		printf("Introduce una cadena de caracteres: ");
		gets(var[i].cadena);
	}

	for(i=0; i<n; i++){
		a=pthread_create(&th[i], NULL, (void*) modificar, (void**)&var[i]);
		if(a!=0){
			printf("Error en el create de la hebra %d\n",i);
			exit(-1);
		}
	}
	
	for(i=0; i<n; i++){
		a=pthread_join(th[i], (void**)&aux);
		if(a!=0){
			printf("Error en el create de la hebra %d\n",i);
			exit(-1);
		}
		printf("Para la hebra %d tiene numero %d y cadena %s\n\n", i, (int)(aux->num), (char*)(aux->cadena));
	}


	pthread_exit(NULL);
}

void* modificar(void* arg){

	struct param* aux = (struct param*)malloc(sizeof(struct param));
	aux=(struct param*)arg;	

	(aux->num)++;
	(aux->cadena)[0]='9';
	pthread_exit((void*)aux);
}
