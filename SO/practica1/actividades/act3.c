#include <sys/types.h>
#include <wait.h>
#include <unistd.h>
#include <stdio.h>
#include <errno.h>
#include <stdlib.h>

int main(int argc, char ** argv){

	pid_t pid;
	
	int n,i, estado, vector[2], status;


	if(argc!=3){
		printf("Error en linea de ordenes: <ejecutable> <num para factorial> <num para factorial\n");
	}

	

	for (i=1; i<=2; i++){
		
		pid = fork();

		switch(pid)
		{
		case -1: /* error del fork() */
			perror("fork error");
			printf("errno value= %d\n", errno);
			break;
		case 0: /* proceso hijo */
			printf("Soy un hijo con ID %d y mi padre = %d \n", getpid(), getppid());
	
			if(execlp("./act3func.exe","./act3func.exe",argv[i],NULL)==-1)
			{
				perror("Falla en la ejecucion exec de ls -l");
				printf("errno value= %d\n", errno);
				exit(EXIT_FAILURE);
			}

			sleep(1);
			exit(EXIT_SUCCESS);
		
		default: /* padre */ 
	
			
			printf("Soy el padre con ID %d; y he creado a mi hijo  %d correctamente\n", getpid(), i);
			while(wait(&status)!=pid);
			printf("Proceso completado.\n");
	
		}
	
		if(pid==0)
		break;
	}

	exit(EXIT_SUCCESS);
}
