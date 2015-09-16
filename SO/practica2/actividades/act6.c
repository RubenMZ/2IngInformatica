#include<stdio.h>
#include<pthread.h>
#include<stdlib.h>
#include<time.h>


struct parametros {
	float escalar ;
	float matriz [3][3];
};

void* calculo(void* estructura);

int main(){

	struct parametros var1, var2, *aux1, *aux2;
	srand(time(NULL));
	int a, b;
	int i, j;
	pthread_t hebra1, hebra2;

	for(i=0; i<3; i++){
		for(j=0; j<3;j++){
			var1.matriz[i][j]= rand()%10+1;
			var2.matriz[i][j]= rand()%10+1;
		}
	}

	var1.escalar=rand()%10+1;
	var2.escalar=rand()%10+1;

	printf("La matriz1 sin multiplicar por %.0f: \n", var1.escalar);
	for(i=0; i<3; i++){
		printf("| ");
		for(j=0; j<3;j++){
			printf(" %.0f ", var1.matriz[i][j]);	
		}
		printf(" |\n");
	}

	printf("La matriz2 sin multiplicar por %.0f: \n", var2.escalar);
	for(i=0; i<3; i++){
		printf("| ");
		for(j=0; j<3;j++){
			printf(" %.0f ", var2.matriz[i][j]);	
		}
		printf(" |\n");
	}


	a=pthread_create(&hebra1, NULL, (void*)calculo, (void**)&var1);
	b=pthread_create(&hebra2, NULL, (void*)calculo, (void**)&var2);

	if(a!=0){
		printf("Error en el create de la hebra1\n");
		exit(-1);
	}else{
		printf("Creada la primera hebra con exito.\n\n");
	}
	if(b!=0){
		printf("Error en el create de la hebra2\n");
		exit(-1);
	}else{
		printf("Creada la segunda hebra con exito.\n\n");
	}

	


	a=pthread_join(hebra1,(void**)&aux1);
	b=pthread_join(hebra2,(void**)&aux2);

	if(a!=0){
		printf("Error en el join de la hebra1\n");
		exit(-1);
	}
	if(b!=0){
		printf("Error en el join de la hebra2\n");
		exit(-1);
	}

		printf("La matriz1 multiplicada por %.0f: \n", var1.escalar);

	for(i=0; i<3; i++){
		printf("| ");
		for(j=0; j<3;j++){
	
			printf(" %.0f ", (float)(aux1->matriz[i][j]));	
		}
		printf(" |\n");
	}

		printf("La matriz2 multiplicada por %.0f: \n", var2.escalar);
	for(i=0; i<3; i++){
		printf("| ");
		for(j=0; j<3;j++){
			printf(" %.0f ", (float)(aux2->matriz[i][j]));	
		}
		printf(" |\n");
	}

	pthread_exit(NULL);
}


void* calculo(void* estructura){

	struct parametros* aux = (struct parametros*) malloc(sizeof(struct parametros));
	aux= (struct parametros*) estructura;
	int i, j;
	float ** resultado= (float**)malloc(sizeof(float*)*3);

	for(i=0;i<3; i++){
		resultado[i]=(float*)malloc(sizeof(float)*3);
	}

	for(i=0; i<3; i++){
		for(j=0; j<3;j++){
			aux->matriz[i][j]= (aux->matriz[i][j])*(aux->escalar)*(1.0);
			
		}
	}

	pthread_exit((void*)aux);
}
