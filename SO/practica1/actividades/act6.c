#include<sys/types.h>
#include <errno.h>
#include <unistd.h>
#include <wait.h>
#include <stdio.h>
#include <stdlib.h>


int main(int argc, char** argv){

	if(argc<4){
		printf("Error argumentos <ejecutable><calculadora><editor><ficheros>\n");
		exit(-1);
	}
	
	int i, j, status;
	pid_t pid;

	for(i=1; i<=2; i++){

	pid=fork();
	if(pid==0)/*hijo*/
		break;

	}

		switch(pid){
		
			case -1: perror("fork error");
				printf("errno value %d\n", errno);
				break;

			case 0: 
				if(i==1){
					
					printf("Soy el hijo %d con padre %d pa abrir la calculadora\n", getpid(), getppid());
					execlp(argv[1], argv[1], NULL);
					
					printf("Se abrio la calculadora.\n");
					exit(EXIT_SUCCESS);
				}else{

					printf("Soy el hijo %d con padre %d pa abrir el gedit\n", getpid(), getppid());
										
						execvp(argv[2], &argv[2]);
					
					printf("Se abrio el gedit.\n");
					exit(EXIT_SUCCESS);
				}
				break;

			default: printf("Soy el padre %d creador.\n", getpid());
				wait(&status);
				printf("Termino mi hijo con estado %d.\n", WEXITSTATUS(status));
			
		}
	
	
	exit(EXIT_SUCCESS);
}
