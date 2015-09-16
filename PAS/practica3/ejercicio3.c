#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <time.h>
#include <mqueue.h>
#include <errno.h>
#include <sys/wait.h>


int main() {

	int fildes[2];
	int status;
	int died;
	pid_t pid;
	int numeroAleatorio;
	int buffer[5];
	int i=0, j=0;
	ssize_t nbytes;

	status = pipe(fildes);

	if(status==-1){
			printf ("Error al crear la tuberia pipe \n");
			exit(1);
	}

	pid = fork();

	switch (pid)
	{
		// Error
		case -1:
			printf ("No he podido crear el proceso hijo \n");
			exit(1);

		// Hijo
		case 0:

			printf ("[HIJO]: mi PID es %d y mi PPID es %d\n", getpid(), getppid());

			//No vamos a escribir
			close(fildes[1]);

			//Vamos a leer
			for(i=0; i<5; i++){ 
				read(fildes[0], &buffer[i], sizeof(buffer[i]));
				printf("[HIJO]: leemos el número aleatorio %d de la tuberia\n", buffer[i]);
			}

			close(fildes[0]);

			printf("[HIJO]: Todo leido... tubería cerrada. Salgo...\n");

			break;

		// Padre
		default:


			printf ("[PADRE]: mi PID es %d y el PID de mi hijo es %d \n", getpid(), pid);
			printf ("[PADRE]: voy a escribir\n");

			//No vamos a leer
			close(fildes[0]);
			
			// Generamos los mensajes 

			srand(time(NULL));
				
			for(j=0; j<5; j++){
				// Número aleatorio entre 0 y 4999
				numeroAleatorio = rand()%5000;
				write(fildes[1], &numeroAleatorio, sizeof(numeroAleatorio));
				printf("[PADRE]: escribimos el número aleatorio %d en la tuberia...\n", numeroAleatorio);
				//sleep(5);
			}

			close(fildes[1]);


			printf("[PADRE]: tubería cerrada\n");

			died=wait(&status);
			printf("[PADRE]: El proceso hijo con PID %d ha salido con código de error %d. Salgo...\n", died, status);			
	}

	exit(0);
}
