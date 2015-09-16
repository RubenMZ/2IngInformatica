#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>

void * th (void *arg)
{
     long y = 10;
	  /*Tenemos que devolver un puntero, es decir, una direccion de memoria a un tipo de dato,
	  y castearla a void * */
     pthread_exit((void *)&y); 
}

int main(int argn, char ** argp)
{
     int s;
	  long nm;
	  long *ret;
     pthread_t thread;
     
     pthread_create(&thread, NULL, th, NULL);
     
     s=pthread_join(thread,(void**) &ret); //Recogemos el resultado devuelto por  pthread_exit() en ret.
     
     if(s!=0)
	  {
		  perror("Fallo en el join...\n");		
        exit(EXIT_FAILURE);
     }
	  else
	  {	  
			nm = *(long *)ret; 
	      printf("Imprimiendo basura:%ld\n", nm);
	  }   
     return 0;
}

