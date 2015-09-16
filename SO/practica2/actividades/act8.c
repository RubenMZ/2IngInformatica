#include<stdio.h>
#include<pthread.h>

long global=0;


void* incremento(void* arg);


int main(){

	pthread_t thread1, thread2;

	pthread_create(&thread1, NULL, (void*)incremento, NULL);
	pthread_create(&thread2, NULL, (void*)incremento, NULL);

	pthread_join(thread1, NULL);
	pthread_join(thread2, NULL);

	printf("\nLa variable global es: %ld\n\n", global);

	pthread_exit(NULL);
}

void* incremento(void* arg){

	int i;

	for(i=0;i<50; i++){
		global++;
	}

	pthread_exit(NULL);
}
