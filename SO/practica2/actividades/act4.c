
#include<pthread.h>
#include<stdio.h>
#include <stdlib.h>
#include<string.h>
void * conversion(void * nombre);
int main(int argc, char* argv[]){
if(argc!=5){
printf("ERROR. Linea de argumentos <ejecutable><video1><video2><mp3_1><mp3_2>\n\n");
exit(-1);
}
int a=0,b=0;
pthread_t hebra1, hebra2;
char*cad1[2];
cad1[0]=argv[1];
cad1[1]=argv[3];
char*cad2[2];
cad2[0]=argv[2];
cad2[1]=argv[4];
a=pthread_create(&hebra1, NULL, (void*)conversion, (void**)cad1);
b=pthread_create(&hebra2, NULL, (void*)conversion, (void**)cad2);
if(a!=0)
printf("ERROR en el create 1\n");
if(b!=0)
printf("ERROR en el create 2\n");
a=pthread_join(hebra1,NULL);
b=pthread_join(hebra2, NULL);
if(a!=0)
printf("ERROR en el create 1\n");
if(b!=0)
printf("ERROR en el create 2\n");
pthread_exit(NULL);
}
void * conversion(void * nombre){
char** video = (char**)nombre;
char cadena[300];
strcpy(cadena, "ffmpeg -i ");
strcat(cadena, video[0]);
strcat(cadena, " -f mp3 -ab 192000 -ar 48000 -vn ");
strcat(cadena, video[1]);
system(cadena);
pthread_exit(NULL);
}
