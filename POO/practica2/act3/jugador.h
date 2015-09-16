#ifndef JUGADOR_H
#define JUGADOR_H

#include"persona.h"
#include<string>
#include<list>

using namespace std;

struct apuestas{
	int tipoApuesta, cantApuesta;
	string valorApuesta; 
};


class Jugador:public Persona{

	private:
		int dinero_;
		string codigoJugador_;
		list<apuestas> apuestas_;
		

		


	public:
		/*Constructor*/
		Jugador(string DNI, string codigoJugador, string nombre="", string apellidos="", string direccion="", string localidad="", string provincia="", string pais="", int dinero=1000);

		/*Modificadores*/
		void setCodigoJugador(string code);
		void setDinero(int num);

		/*Observadores*/
		int getDinero(){return(dinero_);};
		string getCodigoJugador(){return(codigoJugador_);};
		

		/*METODOS*/
		list<apuestas> getApuestas(){return(apuestas_);};
		void setApuestas();
};


#endif
