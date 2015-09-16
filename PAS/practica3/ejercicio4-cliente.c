#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <mqueue.h>
#include <time.h>
#include <errno.h>
#include <regex.h>
#include <signal.h>

#include "common.h"


// Apuntador al fichero de log (se utilizará en el ejercicio resumen)
FILE *fLog = NULL;
	// Cola del servidor
	mqd_t mq_server;
	//Cola del cliente
	mqd_t mq_client;

	char colaServer[100];
	char colaClient[100];

void funcionLog();
void capturaSignal(int signal);

int main(int argc, char **argv)
{


	int bytes_read;

	// Buffer para intercambiar mensajes
	char buffer[MAX_SIZE];
	char buffReturn[MAX_SIZE];

	char mensajeLog[100];

	//Modificar el nombre de la cola nombre-usuario
	strcpy(colaServer, SERVER_QUEUE);
	strcat(colaServer, "-");
	strcat(colaServer, getenv("USER"));
	strcpy(colaClient, CLIENT_QUEUE);
	strcat(colaClient, "-");
	strcat(colaClient, getenv("USER"));

	// Atributos de la cola
	struct mq_attr attr;

		// Inicializar los atributos de la cola
	attr.mq_maxmsg = 10;        // Maximo número de mensajes
	attr.mq_msgsize = MAX_SIZE; // Maximo tamaño de un mensaje



	//Crear la cola de mensajes del cliente
	mq_client = mq_open(colaClient, O_RDONLY, 0644 , &attr);
	if(mq_client == (mqd_t)-1 ){
        	perror("Error al abrir la cola del cliente");
        	funcionLog("Error al abrir la cola del cliente");
       		exit(-1);
	}

	// Abrir la cola del servidor
	mq_server = mq_open(colaServer, O_WRONLY);
	if(mq_server == (mqd_t)-1 ){
        	perror("Error al abrir la cola del servidor");
        	funcionLog("Error al abrir la cola del cliente");
       		exit(-1);
	}

	printf("Mandando mensajes al servidor (escribir \"%s\" para parar):\n", MSG_STOP);
	funcionLog("Mandando mensajes al servidor");

	do {

		printf("> ");
		fflush(stdout);                  // Limpiar buffer de salida

		if (signal(SIGINT, capturaSignal) == SIG_ERR)
        	printf("No puedo asociar la señal SIGINT al manejador!\n");
    	if (signal(SIGHUP, capturaSignal) == SIG_ERR)
        	printf("No puedo asociar la señal SIGHUP al manejador!\n");
    	if (signal(SIGTERM, capturaSignal) == SIG_ERR)
        	printf("No puedo asociar la señal SIGTERM al manejador!\n");


		memset(buffer, 0, MAX_SIZE);     // Poner a 0 el buffer
		fgets(buffer, MAX_SIZE, stdin);  // Leer por teclado
		buffer[strlen(buffer)-1] = '\0'; // Descartar el salto de línea


		// Enviar y comprobar si el mensaje se manda
		if(mq_send(mq_server, buffer, MAX_SIZE, 0) != 0){
			perror("Error al enviar el mensaje");
			funcionLog("Error al enviar el mensaje");
			exit(-1);
		}

		sprintf(mensajeLog, "Mensaje enviado: %s", buffer);
		funcionLog(mensajeLog);

        bytes_read=mq_receive(mq_client, buffReturn, MAX_SIZE, 0);

		if(bytes_read < 0){
			perror("Error al recibir el mensaje");
			funcionLog("Error al recibir el mensaje");
			exit(-1);
		}else{
			printf("%s\n", buffReturn);
			sprintf(mensajeLog, "Mensaje recibido del servidor: %s", buffReturn);
			funcionLog(mensajeLog);
		}

	// Iterar hasta escribir el código de salida
	} while (strncmp(buffReturn, MSG_STOP, strlen(MSG_STOP))!=0);

	// Cerrar la cola del servidor
	
	printf("Cerrando colas...\n");
	funcionLog("Cerrando colas");

	if(mq_close(mq_server) == (mqd_t)-1){
		perror("Error al cerrar la cola del servidor");
		exit(-1);
	}

	// Cerrar la cola del cliente
	if(mq_close(mq_client) == (mqd_t)-1){
		perror("Error al cerrar la cola del cliente");
		exit(-1);
	}

	printf("Colas cerradas\n");
	funcionLog("Colas cerradas");



	return 0;
}





// Función auxiliar, escritura de un log
void funcionLog(char *mensaje) {
	int resultado;
	char nombreFichero[100];
	char mensajeAEscribir[300];
	time_t t;

	// Abrir el fichero
	sprintf(nombreFichero,"log-cliente.txt");
	if(fLog==NULL){
		fLog = fopen(nombreFichero,"at");
		if(fLog==NULL){
			perror("Error abriendo el fichero de log");
			exit(1);
		}
	}

	// Obtener la hora actual
	t = time(NULL);
	struct tm * p = localtime(&t);
	strftime(mensajeAEscribir, 1000, "[%Y-%m-%d, %H:%M:%S]", p);

	// Vamos a incluir la hora y el mensaje que nos pasan
	sprintf(mensajeAEscribir, "%s ==> %s\n", mensajeAEscribir, mensaje);
	
	// Escribir finalmente en el fichero
	resultado = fputs(mensajeAEscribir,fLog);
	if ( resultado < 0)
		perror("Error escribiendo en el fichero de log");

	fclose(fLog);
	fLog=NULL;
}


void capturaSignal(int signal){

	char mensaje[MAX_SIZE];

	switch(signal){
		case 15: printf("Capturada la señal SIGTERM con valor %d\n", signal);
				sprintf(mensaje, "Capturada la señal SIGTERM con valor %d", signal);
				funcionLog(mensaje);
						break;
		case 2: printf("Capturada la señal SIGINT con valor %d\n", signal);
				sprintf(mensaje, "Capturada la señal SIGINT con valor %d", signal);
				funcionLog(mensaje);
						break;
		case 1: printf("Capturada la señal SIGHUP con valor %d\n", signal);
				sprintf(mensaje, "Capturada la señal SIGHUP con valor %d", signal);
				funcionLog(mensaje);
						break;

		default: printf("No se ha encontrado la señal %d\n",signal);
				sprintf(mensaje, "No se ha encontrado la señal %d\n",signal);
				funcionLog(mensaje);
					break;
	}

	// Enviar mensaje para cerrar cliente
	strcpy(mensaje, "exit");
	if(mq_send(mq_server, mensaje, MAX_SIZE, 0) != 0){
		perror("Error al enviar el mensaje");
		exit(-1);
	}
	
	printf("Cerrando y eliminando colas...\n");
	funcionLog("Cerrando y eliminando colas...");
		// Cerrar la cola del servidor
	if(mq_close(mq_server) == (mqd_t)-1){
		perror("Error al cerrar la cola del servidor");
		funcionLog("Error al cerrar la cola del servidor");
		exit(-1);
	}

	// Cerrar la cola del cliente
	if(mq_close(mq_client) == (mqd_t)-1){
		perror("Error al cerrar la cola del cliente");
		funcionLog("Error al cerrar la cola del cliente");
		exit(-1);
	}

	printf("Colas cerradas\n");
	funcionLog("Colas cerradas");


	printf("Cerrando ficheros...\n");
	funcionLog("Cerrando ficheros...");
	if(fLog!=NULL){
		fclose(fLog);
		printf("Fichero cerrado\n");
		funcionLog("Fichero cerrado");
	}
		
	exit(-1);
}