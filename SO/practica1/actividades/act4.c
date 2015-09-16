#include <sys/types.h>
#include <unistd.h>
#include <stdio.h>
#include <errno.h>
#include <stdlib.h>

int main(){

	pid_t pid;

	pid = fork();

	switch(pid){


		case -1: perror("fork error");
			printf("errno value = %d\n", errno);
			break;

		case 0: printf("\nSoy el hijo con ID %d y mi padre %d\n", getpid(), getppid());
			break;
		
		default: sleep(30);
			printf("\nSoy el padre con ID %d\n", getpid());
			exit(EXIT_SUCCESS);

	}		

	exit(EXIT_SUCCESS);
}
