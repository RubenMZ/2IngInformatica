#include <stdio.h>
#include <stdlib.h>


int main(int argc, char** argv){

	int num, resultado=1,i;

	if(argc!=2){
		printf("Error linea de ordenes: <ejecutable><numero para factorial>\n");
		exit(-1);

	}
	num = atoi(argv[1]);

		

	for(i=1; i<=num; i++){
	
		resultado = resultado *i; 

	}

		printf("\nCalculando...\n");
		sleep(2);			

		printf("\nFactorial de %d es %d\n", num, resultado);

		sleep(2);

	exit(EXIT_SUCCESS);

}
