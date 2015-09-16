#include<sys/types.h>
#include<wait.h>
#include<errno.h>
#include<unistd.h>
#include<stdio.h>
#include<stdlib.h>


int main(int argc , char** argv){

	if(argc!=3){
		printf("Error en linea de argumentos: <ejecutable><segundos para dormir al hijo><valor del estado de hijo>\n");
		exit(-1);
	}

	int seconds= atoi(argv[1]), status = atoi(argv[2]);
	int estado;
	pid_t pid = fork();

	switch(pid){
	
		case -1: perror("fork error");
			printf("errno value: %d\n", errno);
			break;

		case 0: printf("\nSoy el hijo %d con mi padre %d\n", getpid(), getppid());
			sleep(seconds);
				
			exit(status);

		default: wait(&estado);

			if(WEXITSTATUS(estado)==status){
				printf("Mi hijo termino correctamente con estado %d = %d\n", WEXITSTATUS(estado), status);
				exit(EXIT_SUCCESS);
			}else{
				printf("Mi hijo se interrumpio con estado %d distinto de %d\n", WEXITSTATUS(estado), status);
				exit(EXIT_FAILURE);
			}
			
			


	}

	exit(EXIT_SUCCESS);
}
