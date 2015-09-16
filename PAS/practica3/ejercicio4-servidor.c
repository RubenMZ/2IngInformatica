#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <mqueue.h>
#include <time.h>
#include <errno.h>
#include <regex.h>
#include <getopt.h>
#include <unistd.h>
#include <ctype.h>
#include <signal.h> 

#include "common.h"

// Apuntador al fichero de log (se utilizará en el ejercicio resumen)
FILE *fLog = NULL;
// flag que indica cuando hay que parar
int must_stop = 0;

	// Cola del servidor
	mqd_t mq_server;
	//Cola del cliente
	mqd_t mq_client;
    char colaServer[100];
	char colaClient[100];


void ayuda();
void funcionLog();
void capturaSignal(int signal);

int main(int argc, char **argv)
{


	char c;
	int hflag=0;
	int eflag=0;
	int rflag=0;
	char * rValue=0;
	int checkRegex=0;
	regex_t regex;
	int checkStatus=0;
	char mensajeLog[100];




	   /* Estructura a utilizar por getoptlong */
    static struct option long_options[] =
    {
        /* Opciones que no van a actuar sobre un flag */
        /* "opcion", recibe o no un argumento, 0,
           identificador de la opción */
        {"regex",required_argument,0, 'r'},
        {"ere",  no_argument, 0, 'e'},
        {"help", no_argument, 0, 'h'},
        /* Necesario para indicar el final de las opciones */
        {0, 0, 0, 0}
    };

    int option_index=0;



	//Modificar el nombre de la cola nombre-usuario
	strcpy(colaServer, SERVER_QUEUE);
	strcat(colaServer, "-");
	strcat(colaServer, getenv("USER"));
	strcpy(colaClient, CLIENT_QUEUE);
	strcat(colaClient, "-");
	strcat(colaClient, getenv("USER"));
	

	// Atributos de la cola
	struct mq_attr attr;

	// Buffer para intercambiar mensajes
	char buffer[MAX_SIZE + 1];
	char buffReturn[MAX_SIZE];


	// Inicializar los atributos de la cola
	attr.mq_maxmsg = 10;        // Maximo número de mensajes
	attr.mq_msgsize = MAX_SIZE; // Maximo tamaño de un mensaje

		while ((c = getopt_long (argc, argv, "r:eh", long_options, &option_index)) != -1)
    {
        switch (c)
        {

        case 'r':
        	rflag=1;
        	rValue=optarg;
            break;

        case 'e':
        	eflag=1;
        	break;

        case 'h':
        	ayuda();
        	hflag=1;
        	break;
        case '?':

            opterr=0;

			if (optopt == 'r'){
                fprintf (stderr, "La opción -%c requiere un argumento.\n", optopt);
                sprintf(mensajeLog, "La opción -%c requiere un argumento.", optopt);
                funcionLog(mensajeLog);
                ayuda();
                hflag=1;
            }else{
                if (isprint (optopt)){
                    fprintf (stderr, "Opción desconocida '-%c'.\n", optopt);
                    sprintf(mensajeLog, "Opción desconocida '-%c'.", optopt);
                	funcionLog(mensajeLog);
                    ayuda();
                    hflag=1;
                }else{
                    fprintf (stderr, "Caracter `\\x%x'.\n", optopt);
                    sprintf(mensajeLog, "Caracter `\\x%x'.", optopt);
                	funcionLog(mensajeLog);                    
                    ayuda();
                    hflag=1;
                }
            }


            return 1;
        default:
            abort ();

        }//switch
    }//while

	// Crear la cola de mensajes del servidor
	mq_server = mq_open(colaServer, O_CREAT | O_RDONLY, 0644, &attr);
	if(mq_server == (mqd_t)-1 ){
        	perror("Error al abrir la cola del servidor");
        	funcionLog("Error al abrir la cola del servidor");
       		exit(-1);
	}

	//Abrir la cola de mensajes del cliente
	mq_client = mq_open(colaClient, O_CREAT|O_WRONLY);
	if(mq_client == (mqd_t)-1 ){
        	perror("Error al abrir la cola del cliente");
        	funcionLog("Error al abrir la cola del cliente");
       		exit(-1);
	}

	do {
		// Número de bytes leidos
		ssize_t bytes_read;

	if (signal(SIGINT, capturaSignal) == SIG_ERR)
        printf("No puedo asociar la señal SIGINT al manejador!\n");
    if (signal(SIGHUP, capturaSignal) == SIG_ERR)
        printf("No puedo asociar la señal SIGHUP al manejador!\n");
    if (signal(SIGTERM, capturaSignal) == SIG_ERR)
        printf("No puedo asociar la señal SIGTERM al manejador!\n");


		// Recibir el mensaje
		bytes_read = mq_receive(mq_server, buffer, MAX_SIZE, NULL);
		// Comprar que la recepción es correcta (bytes leidos no son negativos)
		if(bytes_read < 0){
			perror("Error al recibir el mensaje");
			funcionLog("Error al recibir el mensaje");
			exit(-1);
		}

		// Cerrar la cadena
		buffer[bytes_read] = '\0';

		// Comprobar el fin del bucle
		if (strncmp(buffer, MSG_STOP, strlen(MSG_STOP))==0){
			must_stop = 1;
			if(strncmp(buffer, MSG_STOP, sizeof(MSG_STOP))==0){
				strcpy(buffReturn, "exit");
			}
		}else{
			printf("Recibido el mensaje: %s\n", buffer);
			sprintf(mensajeLog, "Recibido el mensaje: %s", buffer);
			funcionLog(mensajeLog);
			if (hflag==1)
			{
				ayuda();
				abort();
			}


			if(rflag==1){//Expresion regular
				
				if (eflag==1)
				{
					checkRegex=regcomp(&regex,rValue,REG_EXTENDED);
					if(checkRegex!=0){
						printf("Error regex\n");
						funcionLog("Error regex");
						exit(-1);
					}else{
						checkStatus=regexec(&regex, buffer, (size_t)0, NULL, 0);
						if (checkStatus!=0)
						{
						strcpy(buffReturn, "No empareja");
						}else{
						strcpy(buffReturn, "Empareja");
						}
					}


				}else{
					checkRegex=regcomp(&regex,rValue,0);
					if(checkRegex!=0){
						printf("Error regex\n");
						funcionLog("Error regex");
						exit(-1);
					}else{
						checkStatus=regexec(&regex, buffer, (size_t)0, NULL, 0);
						if (checkStatus!=0)
						{
						strcpy(buffReturn, "No empareja");
						}else{
						strcpy(buffReturn, "Empareja");
						}
					}

				}


			}else{
					checkRegex=regcomp(&regex,"[A-Z]",0);
					if(checkRegex!=0){
						printf("Error regex\n");
						funcionLog("Error regex");
						exit(-1);
					}else{
						checkStatus=regexec(&regex, buffer, (size_t)0, NULL, 0);
						if (checkStatus!=0)
						{
						strcpy(buffReturn, "No empareja");
						}else{
						strcpy(buffReturn, "Empareja");
						}
					}
			}


		}

		sprintf(mensajeLog, "Se envia al cliente el mensaje: %s", buffReturn);
		funcionLog(mensajeLog);

		// Enviar y comprobar si el mensaje se manda
		if(mq_send(mq_client, buffReturn, MAX_SIZE, 0) != 0){
			perror("Error al enviar el mensaje");
			exit(-1);
		}
	// Iterar hasta que llegue el código de salida
	} while (!must_stop);

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

	// Eliminar la cola del servidor
	if(mq_unlink(colaServer) == (mqd_t)-1){
		perror("Error al eliminar la cola del servidor");
		funcionLog("Error al eliminar la cola del servidor");
		exit(-1);
	}


		// Eliminar la cola del cliente
	if(mq_unlink(colaClient) == (mqd_t)-1){
		perror("Error al eliminar la cola del cliente");
		funcionLog("Error al eliminar la cola del cliente");
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
	sprintf(nombreFichero,"log-servidor.txt");
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


void ayuda(){
            printf("Uso del programa: ejercicio4-servidor [opciones]\n");
            printf("Opciones:\n");
            printf("-h, --help\t");
            printf("Imprimir esta ayuda\n");
            printf("-r, --regex=EXPR\t");
            printf("Expresion regular a utilizar \n");
            printf("-e, --ere\t");
            printf("Utilizar expresiones regulares de tipo ERE\n"); 
            exit(-1); 
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
	if(mq_send(mq_client, mensaje, MAX_SIZE, 0) != 0){
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

	// Eliminar la cola del servidor
	if(mq_unlink(colaServer) == (mqd_t)-1){
		perror("Error al eliminar la cola del servidor");
		funcionLog("Error al eliminar la cola del servidor");
		exit(-1);
	}


		// Eliminar la cola del cliente
	if(mq_unlink(colaClient) == (mqd_t)-1){
		perror("Error al eliminar la cola del cliente");
		funcionLog("Error al eliminar la cola del cliente");
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