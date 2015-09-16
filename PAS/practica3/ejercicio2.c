#include <stdio.h>
#include <unistd.h>
#include <ctype.h>
#include <stdlib.h>
#include <string.h>
#include <pwd.h>
#include <grp.h>
#include <getopt.h>

    void ayuda();

int main (int argc, char** argv){

	char c;
	int eflag=0;
	int sflag=0;
	int gflag=0;
	int hflag=0;
	char * name=NULL;
	char * group=NULL;
	int groupid=0;
	struct passwd *pw;
    struct group *gr;

    /* Estructura a utilizar por getoptlong */
    static struct option long_options[] =
    {
        /* Opciones que no van a actuar sobre un flag */
        /* "opcion", recibe o no un argumento, 0,
           identificador de la opción */
        {"group",required_argument,0, 'g'},
        {"spanish",  no_argument,    0, 's'},
        {"english", no_argument, 0, 'e'},
        {"help",no_argument, 0, 'h'},
        /* Necesario para indicar el final de las opciones */
        {0, 0, 0, 0}
    };

    int option_index=0;


    while ((c = getopt_long (argc, argv, "eshg:", long_options, &option_index)) != -1)
    {
        switch (c)
        {

        case 'g':
        	gflag=1;
        	group = optarg;
        	if((gr = getgrnam(group)) ==NULL)
        	{
        		printf("No existe ese grupo\n");
        		exit(-1);
        	}
            break;

        case 'e':
        	if(sflag==1){
        		printf("No se puede activar dos idiomas al mismo tiempo.\nTwo languages cannot be used at same time\n");
        		ayuda();
                exit(-1);
        	}else{
        		eflag=1;
        	}
            break;

        case 's':
        	if(eflag==1){
        		printf("No se puede activar dos idiomas al mismo tiempo.\nTwo languages cannot be used at same time\n");
        		ayuda();
                exit(-1);
        	}else{
        		sflag=1;
        	}
            break;

        case 'h':
            hflag=1;
        	break;

        case '?':

            opterr=0;

			if (optopt == 'g'){
                fprintf (stderr, "La opción -%c requiere un argumento.\n", optopt);
                ayuda();
                hflag=1;
            }else{

                if (isprint (optopt)){
                    fprintf (stderr, "Opción desconocida '-%c'.\n", optopt);
                    ayuda();
                    hflag=1;
                }else{
                    fprintf (stderr, "Caracter `\\x%x'.\n", optopt);
                    ayuda();
                    hflag=1;
                }
            }


            return 1;
        default:
            abort ();
        


        }
    }//while

    if(hflag==1){
        ayuda();
    }

    if(eflag==0 && sflag==0 && strstr(getenv("LANG"),"ES")){
		sflag=1;
    }

    if(gflag==0){
    	name=getenv("USER");
    	pw=getpwnam(name);
    	groupid=pw->pw_gid;
    	gr=getgrgid(groupid);
    }

    

    if(sflag==1){
    	//En español
    		printf("Numero del grupo principal: %d\n", gr->gr_gid);
    		printf("Nombre del grupo principal: %s\n", gr->gr_name);
    }else{
    	//En ingles
    		printf("Main group number: %d\n", gr->gr_gid);
    		printf("Main group name: %s\n", gr->gr_name);
    }


	return 0;
}

void ayuda(){
            printf("Uso del programa: ejercicio2 [opciones]\n");
            printf("Opciones:\n");
            printf("-h, --help\t");
            printf("Imprimir esta ayuda\n");
            printf("-g, --group=GRUPO\t");
            printf("Grupo a analizar \n");
            printf("-e, --english\t");
            printf("Mensajes en inglés\n");
            printf("-s, --spanish\t");
            printf("Mensajes en castellano\n");  
            exit(-1); 
}