#include<stdio.h>
#include<time.h>
#include<stdlib.h>

void * hebra();

int main(){

	int n, i, suma=0;
	void *resultado;

	printf("Ingresa el numero de hebras para crear: ");
	scanf("%d", &n);

	pthread_t th[n];

	for(i=0; i<n; i++)
		pthread_create(&th[i], NULL, (void*)hebra, NULL);

	for(i=0; i<n; i++){
		pthread_join(th[i], (void**)&resultado);
		suma+=*(int*)resultado;
	}

	printf("La suma total es %d\n", suma);

	pthread_exit(NULL);
}


void * hebra(){

	
	srand(time(NULL));
	int * suma = (int*)malloc(sizeof(int));

	int n1=rand()%10, n2=rand()%10;

	*suma = n1+n2;
	printf("n1 = %d y n2 = %d cuya suma es: %d\n", n1, n2, *suma);


	pthread_exit((void*)suma);
}
