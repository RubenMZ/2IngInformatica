#include <sys/types.h>
#include <stdio.h>
#include <unistd.h>
#include <errno.h>
#include <stdlib.h>

int main(){

	pid_t pid;
	
	int n,i, estado;

	printf("Introduce el numero de hijos para crear: ");
	scanf("%d", &n);

	for (i=1; i<=n; i++){
		
		pid = fork();

	
	

		switch(pid)
		{
		case -1: /* error del fork() */
			perror("fork error");
			printf("errno value= %d\n", errno);
			exit (EXIT_FAILURE);
		case 0: /* proceso hijo */
			printf("Soy un hijo con ID %d y mi padre = %d \n", getpid(), getppid());
			sleep(10*i);
			exit(EXIT_SUCCESS);
		
		default: /* padre */ 
	
			
			printf("Soy el padre con ID %d; y he creado a mi hijo  %d correctamente\n", getpid(), i);
		
	
		}
	
	}

	while((pid=wait(&estado))!=-1)
	 	{
		if(WIFEXITED(estado)){
							
			printf("El hijo %d termino correcto con estado %d\n", pid, WEXITSTATUS(estado));
		}else{
			printf("Ocurrio un error.\n");
		}
		}

	
		
		



	return (EXIT_SUCCESS);
}
