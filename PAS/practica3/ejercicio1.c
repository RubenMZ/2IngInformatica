#include <stdio.h>
#include <unistd.h>
#include <ctype.h>
#include <stdlib.h>
#include <string.h>
#include <pwd.h>
#include <grp.h>

int main (int argc, char** argv){

	char c;
	int nflag=0;
	int uflag=0;
	int eflag=0;
	int sflag=0;
	int gflag=0; 
	char * name=NULL;
	int iduser=0;
	struct passwd *pw;
    struct group *gr;


    while ((c = getopt (argc, argv, "gesn:u:")) != -1)
    {
        switch (c)
        {
        case 'n':
        	if(uflag==1){
        		printf("UID y usuario no pueden ser usados al mismo tiempo\nUID and user name should not be used at the same time\n");
        		exit(-1);
        	}else{
        		nflag=1;
        		name=optarg;
        		pw=getpwnam(name);
        	}

            break;

        case 'u':
        	if(nflag==1){
        		printf("UID y usuario no pueden ser usados al mismo tiempo\nUID and user name should not be used at the same time\n");
        		exit(-1);
        	}else{
        		uflag=1;
        		iduser=atoi(optarg);
        		pw=getpwuid(iduser);
        	}
            break;

        case 'g':
        	gflag=1;
            break;

        case 'e':
        	if(sflag==1){
        		printf("No se puede activar dos idiomas al mismo tiempo.\nTwo languages cannot be used at same time\n");
        		exit(-1);
        	}else{
        		eflag=1;
        	}
            break;

        case 's':
        	if(eflag==1){
        		printf("No se puede activar dos idiomas al mismo tiempo.\nTwo languages cannot be used at same time\n");
        		exit(-1);
        	}else{
        		sflag=1;
        	}
            break;

        case '?':
			if (optopt == 'u' || optopt == 'n')
                fprintf (stderr, "La opción -%c requiere un argumento.\n", optopt);
            else if (isprint (optopt))
                fprintf (stderr, "Opción desconocida '-%c'.\n", optopt);
            else
                fprintf (stderr, "Caracter `\\x%x'.\n", optopt);
            return 1;
        default:
            abort ();
        }
    }

    if(eflag==0 && sflag==0 && strstr(getenv("LANG"),"ES")){
		sflag=1;
    }

    if(nflag==0 && uflag==0){
    	name=getenv("USER");
    	pw=getpwnam(name);
    }



    if(sflag==1){
    	//En español
    	printf("Nombre de usuario: %s\n", pw->pw_name);
    	printf("Identificador de usuario: %d\n", pw->pw_uid);
    	printf("Contraseña: %s\n", pw->pw_passwd);
    	printf("Carpeta de inicio: %s\n", pw->pw_dir);
    	printf("Intérprete por defecto: %s\n", pw->pw_shell);

    	if(gflag==1){
    		gr = getgrgid(pw->pw_gid);
    		printf("Numero del grupo principal: %d\n", pw->pw_gid);
    		printf("Nombre del grupo principal: %s\n", gr->gr_name);
    	}
    }else{
    	//En ingles

    	printf("User's name: %s\n", pw->pw_name);
    	printf("User's identifier: %d\n", pw->pw_uid);
    	printf("Password: %s\n", pw->pw_passwd);
    	printf("Home: %s\n", pw->pw_dir);
    	printf("Default shell: %s\n", pw->pw_shell);

    	if(gflag==1){
    		gr = getgrgid(pw->pw_gid);
    		printf("Main group number: %d\n", pw->pw_gid);
    		printf("Main group name: %s\n", gr->gr_name);
    	}
    }


	return 0;
}