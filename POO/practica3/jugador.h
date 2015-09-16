#ifndef JUGADOR_H
#define JUGADOR_H

#include"persona.h"
#include<string>
#include<list>

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
		Jugador(string DNI, string codigoJugador, string nombre="", string apellidos="", string direccion="", string localidad="", string provincia="", string pais=""):Persona(DNI, nombre, apellidos, direccion, localidad, provincia, pais), codigoJugador_(codigoJugador){dinero_=1000;}; //codigo_(codigo) le asigna al campo codigo_ el parametro codigo

		/*Modificadores*/
		inline void setCodigoJugador(string code){codigoJugador_=code;};
		inline void setDinero(int num){dinero_=num;};

		/*Observadores*/
		inline int getDinero(){return(dinero_);};
		inline string getCodigoJugador(){return(codigoJugador_);};
		

		/*METODOS*/
		inline list<apuesta> getApuestas(){return(apuestas_);};
		void setApuestas();
};


#endif
