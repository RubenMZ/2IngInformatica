#include <sys/types.h>
#include <stdio.h>
#include <unistd.h>
#include <errno.h>
#include <stdlib.h>

void main(void)
{
	pid_t pid;
	int n,i;

	printf("Introduce el numero de hijos para crear: ");
	scanf("%d", &n);

	for (i=0; i<n; i++){
		pid = fork();
		if(pid==0)
		break;
	}

	switch(pid)
	{
	case -1: /* error del fork() */
	perror("fork error");
	printf("errno value= %d\n", errno);
	break;
	case 0: /* proceso hijo */
	printf("Soy un hijo con ID %d y mi padre = %d \n", getpid(), getppid());
	break;
	default: /* padre */ 
	
	sleep(2);	 
	 printf("Soy el padre con ID %d; padre = %d \n", getpid(), getppid());
	
	
	}
}
