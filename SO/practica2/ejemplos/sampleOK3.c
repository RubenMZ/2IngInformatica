#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>

/**********************************************************************************************
 Por lo mismo que se ha explicado en el ejercicio "sampleOK2.c" este ejemplo muestra la salida
correcta pero su implementación no es la apropiada. Por tanto no debemos programar con hebras
de esta manera 
**********************************************************************************************/

void * th (void *arg)
{
        long y = 10;
        pthread_exit((void *)y); 
}

int main(int argn, char ** argp)
{
     int s;
	  long nm;
	  long *ret;
     pthread_t thread;
     
     pthread_create(&thread, NULL, th, NULL);
     s=pthread_join(thread,(void *)ret); 
     
     if(s!=0)
	  {
		  perror("Fallo en el join...\n");		
        exit(EXIT_FAILURE);
     }
	  else
	  {	  
			nm = *ret; 
	      printf("%ld\n", nm);
	  }   
     return 0;
}
