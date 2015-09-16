#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>

#define TOTALHILOS 10

void *functionSuma(void* hilo)
{
  fflush (stdout);
  pthread_exit ((void*)hilo);
}


int main (int argc, char *argv[])
{
  if (argc != 2)
    {
      printf ("ERROR. Se necesita <./programa> <número>\n");
      exit (EXIT_FAILURE);
    }

  if ((atoi (argv [1]) < 1) || (atoi (argv [1]) > 10))
    {
      printf ("ERROR. Se espera un número entre 1 y 10.\n");
      exit (EXIT_FAILURE);
    }
  long nHilos = atoi (argv[1]);

  long i, j, suma = 0, sumaFinal = 0;
  long vector [] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
  pthread_t hilos [nHilos];


  for (i = 1 ; i <= TOTALHILOS ; i ++)
    {
      /*pthread_create(se le envían el nº de hilos que nos han pedido)*/
      pthread_create (&hilos[(i-1)%nHilos], NULL, functionSuma, (void*)vector[i-1]);
      sleep (1);
      printf ("Soy el hilo %ld y tengo el número %ld\n", (i-1)%(nHilos)+1, vector[i-1]);
      /*Si todos los hilos han cogido un número...*/
      if (i % nHilos == 0)
        {
          /*Los suma todos y vuelve al pthread create hasta que lo haga TOTALHILOS veces*/
          for (j = 0 ; j < nHilos; j ++)
            {
              pthread_join (hilos[j], (void**)&suma);
              sumaFinal = sumaFinal + suma;
            }
        }
    }
  /*Suma los hilos que no se habían sumado antes*/
  for (i = TOTALHILOS - TOTALHILOS%nHilos ; i < 10 ; i ++)
    {
      pthread_join (hilos[i%nHilos], (void**)&suma);
      sumaFinal = sumaFinal + suma;
      sleep (1);
    }

  printf ("La suma de todos los elementos del vector es %ld.\n", sumaFinal);
  return (0);
}
