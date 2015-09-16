#include<stdio.h>
#include<errno.h>
#include<sys/types.h>
#include<unistd.h>
#include<stdlib.h>


int main(int argc, char** argv){

	if(argc!=2){
		printf("Error argumentos <ejecutable> <nombre fichero a escribir>\n");
		exit(-1);
	}

	FILE* f;
	int i, status,j, k;
	pid_t pid;
	char c;

	if((f= fopen(argv[1], "a"))==NULL){
		printf("NO se puede abrir el fichero\n");
		exit(-1);
	}

	for(i=0; i<2 ; i++){
		pid= fork();
		if(pid==0)
			break;
	}

	switch(pid){

		case -1:
			perror("fork error");
			printf("errno value: %d", errno);

		case 0: /*hijo*/
			
			for(j=0; j<2;j++){
				fprintf(f, "Hijo %d: ------\n", getpid());
				fflush(f);
				printf("Escritura del hijo %d\n", i);
				sleep(3);
			}		
			
			exit(EXIT_SUCCESS);
			break;

		default: /*padre*/
			
			for(k=0; k<3;k++){
				fprintf(f, "Padre %d: ++++++\n", getpid());
				printf("Primera escritura del padre.\n");
				sleep(3);
			}
			

			wait(&status);
			if(WIFEXITED(status)!=0){			
				printf("Mis hijos terminaron con estado %d\n", WEXITSTATUS(status));	
				fflush(f);
				fclose(f);
			}
			
			

			break;
	}

	

	printf("\nEL FICHERO QUEDA ASI\n");


	if((f=fopen(argv[1], "r"))==NULL){
		printf("NO se puede abrir el fichero para leer\n");
		exit(-1);
		
	}
	
	while((c=fgetc(f))!=EOF){
		printf("%c", c);
	
	}

	fclose(f);
	


	
	exit(EXIT_SUCCESS);
}
