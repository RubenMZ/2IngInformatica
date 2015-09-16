#include "jugador.h"
#include "crupier.h"
#include "persona.h"
#include "ruleta.h"
#include <iostream>
#include <unistd.h>
#include <cstdio>

using namespace std;
//using namespace ruleta;

int main(){


	Crupier crupier1("46068656R", "12345");
	char opcion;

	Ruleta ruleta1(crupier1);
	int jugadores, dinero, lanzamientos, ganancia;
	string dni;
	Jugador nuevo("123456789X", "1234");
	string DNI, codigo, nombre, apellidos, direccion, localidad, provincia, pais;

	do{

	cout<<endl<<"Introduce una de las siguientes opciones"<<endl;
	cout<<"-------------------------------------------------------"<<endl<<endl;
	cout<<"\ta) Cargar los jugadores del fichero jugadores.txt"<<endl;
	cout<<"\tb) Guardar los jugadores en jugadores.txt"<<endl;
	cout<<"\tc) Estado de ruleta, dinero de banca y de los jugadores."<<endl;
	cout<<"\td) Girar ruleta mostrar: numero, premios y banca"<<endl;
	cout<<"\te) Eliminar un jugador de la mesa"<<endl;
	cout<<"\tf) Añadir un jugador a la mesa"<<endl;
	cout<<"\tg) Salir del programa"<<endl;
	cout<<endl<<"-------------------------------------------------------"<<endl<<endl;
	cout<<"Opcion -> ";
	cin>>opcion;

	switch(opcion){

		case 'a': 	ruleta1.leeJugadores();
					cout<<"Se han leido los jugadores del fichero"<<endl;
					break;

		case 'b': 	ruleta1.escribeJugadores();
					cout<<"Se han escrito los jugadores en el fichero"<<endl;
					break;

		case 'c': 	ruleta1.getEstadoRuleta(jugadores, dinero, lanzamientos, ganancia);
					cout<<"ESTADISTICAS"<<endl;
					cout<<"----------------------------------------------------"<<endl;
					cout<<"\tNumero de jugadores en la mesa: "<<jugadores<<endl;
					cout<<"\tNumero de lanzamientos: "<<lanzamientos<<endl;
					cout<<"\tDinero sobre la mesa: "<<dinero<<endl;
					cout<<"\t- Dinero de la banca: "<<ruleta1.getBanca()<<endl;
					cout<<"\t- Dinero de los jugadores: "<<dinero-ruleta1.getBanca()<<endl;
					cout<<"\tLa banca obtiene una ganacia de: "<<ganancia<<endl;
					break;

		case 'd': 	ruleta1.giraRuleta();
					ruleta1.getPremios();
					cout<<"La bola ganadora es: "<<ruleta1.getBola()<<endl<<endl;
					cout<<"LOS JUGADORES QUEDAN: "<<endl;
					ruleta1.imprimeJugadores();

					ruleta1.getEstadoRuleta(jugadores, dinero, lanzamientos, ganancia);
					cout<<"Y LA BANCA: "<<ruleta1.getBanca()<<" con una ganacia: "<<ganancia<<endl;

					break;

		case 'e': 	getchar();
					cout<<"Introduce el dni del jugador para borrar: ";
					getline(cin, dni);
					int acierto;
					acierto = ruleta1.deleteJugador(dni);
					if(acierto==1){
						cout<<"Se ha borrado el jugador"<<endl;
					}else{
						if(acierto==-1){
							cout<<"La lista esta vacia"<<endl;
						}else{
							cout<<"El jugador no se encontro"<<endl;
						}
					}

					break;


		case 'f': 	getchar();
					
					cout<<"Introduce el dni: ";
					getline(cin, DNI);
					cout<<"Introduce el codigo: ";
					getline(cin, codigo);
					cout<<"Introduce el nombre: ";
					getline(cin, nombre);
					cout<<"Introduce los apellidos: ";
					getline(cin, apellidos);
					cout<<"Introduce la direccion: ";
					getline(cin, direccion);
					cout<<"Introduce la localidad: ";
					getline(cin, localidad);
					cout<<"Introduce la provincia: ";
					getline(cin, provincia);
					cout<<"Introduce el pais: ";
					getline(cin, pais);

					nuevo.setDNI(DNI); 
					nuevo.setCodigoJugador(codigo);
					nuevo.setNombre(nombre); 
					nuevo.setApellidos(apellidos);
					nuevo.setDireccion(direccion);
					nuevo.setLocalidad(localidad); 
					nuevo.setProvincia(provincia);
					nuevo.setPais(pais);

					ruleta1.addJugador(nuevo);

					break;

		case 'g': 	cout<<endl<<"*****Gracias por su visita*****"<<endl<<endl;
					break;

		default: 	cout<<endl<<"OPCION NO VALIDA"<<endl<<endl; 
					break;

	}

	if(opcion!='g'){
		getchar();
		cout<<"Presiona ENTER para continuar...";
		getchar();
		cout<<endl<<endl<<endl<<endl<<endl<<endl<<endl<<endl;
	}

	}while(opcion!='g');

	return(0);
}
