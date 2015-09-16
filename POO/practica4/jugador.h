#ifndef JUGADOR_H
#define JUGADOR_H

#include "persona.h"
#include <string>
#include <list>

using namespace std;

struct apuesta{
	int tipoApuesta, cantApuesta;
	string valorApuesta; 
};


class Jugador:public Persona{

	private:
		int dinero_;
		string codigoJugador_;
		list<apuesta> apuestas_;
		

		


	public:
		/*Constructor*/
		Jugador(const string DNI, const string &codigoJugador, const string &nombre="", const string &apellidos="", const string &direccion="", const string &localidad="", const string &provincia="", const string &pais=""):Persona(DNI, nombre, apellidos, direccion, localidad, provincia, pais), codigoJugador_(codigoJugador){dinero_=1000;}; //codigo_(codigo) le asigna al campo codigo_ el parametro codigo

		/*Modificadores*/
		inline void setCodigoJugador(const string &code){codigoJugador_=code;};
		inline void setDinero(const int &num){dinero_=num;};

		/*Observadores*/
		inline int getDinero(){return(dinero_);};
		inline string getCodigoJugador(){return(codigoJugador_);};
		

		/*METODOS*/

		/*PROC setApuestas() DEV nada
		REQUIERE Que exista el fichero de apuesta del jugador creado
		MODIFICA La lista de apuestas del jugador
		EFECTOS Abre un fichero DNI.txt y modifica la lista de apuestas de jugador
		DESCRIPCION Abre el fichero numDNI.txt del jugador y copia las apuestas del fichero en su lista de apuestas,
					añadiendo al final de la lista cada apuesta que el jugador haya colocado en el fichero (cada linea)
					*/

		inline list<apuesta> getApuestas(){return(apuestas_);};
		void setApuestas();
};


#endif
