#ifndef RULETA_H
#define RULETA_H

#include <list>
#include<string>
#include"crupier.h"
#include"jugador.h"

using namespace std;

class Ruleta{

	private:/*CAMPOS*/
		int banca_, bola_;
		Crupier crupier_;
		list<Jugador> jugadores_;
	public:
		/*Constructor*/
		Ruleta( Crupier c);

		/*Modificadores*/		

		void setBanca(int num);
		void setBola(int num);
		void setCrupier(Crupier crup);

		/*Observadores*/

		inline int getBanca(){return(banca_);};
		inline int getBola(){return(bola_);};
		inline Crupier getCrupier(){return(crupier_);};
		inline list<Jugador> getJugadores(){return(jugadores_);};

		/*METODOS*/
		void addJugador(Jugador jug);
		int deleteJugador(Jugador jug);
		int deleteJugador(string dni);
		/*Escribe los jugadores en el fichero*/
		void escribeJugadores();
		/*Lee los jugadores del fichero*/
		void leeJugadores();
		void giraRuleta();
		void getPremios();
		/*Muestra los jugadores por pantalla*/
		int imprimeJugadores();
		string color(int bola);

};


#endif
