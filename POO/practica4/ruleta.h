#ifndef RULETA_H
#define RULETA_H

#include <list>
#include <string>
#include "crupier.h"
#include "jugador.h"
#include "persona.h"

using namespace std;



class Ruleta{

	private:/*CAMPOS*/
		int banca_, bola_;
		Crupier crupier_;
		list<Jugador> jugadores_;
		int lanzamientos_;
	public:
		/*Constructor*/
		Ruleta(const Crupier &c);

		/*Modificadores*/		

		void setBanca(const int &num);
		void setBola(const int &num);
		inline void setCrupier(const Crupier &crup){crupier_=crup;};
		inline void setLanzamientos(const int &lanzamientos){lanzamientos_=lanzamientos;};

		/*Observadores*/

		inline int getBanca(){return(banca_);};
		inline int getBola(){return(bola_);};
		inline int getLanzamientos(){return(lanzamientos_);};
		inline Crupier getCrupier(){return(crupier_);};
		inline list<Jugador> getJugadores(){return(jugadores_);};

		/*METODOS*/

		/*	
		PROC addJugador(Jugador jug) DEV nada
		REQUIERE Que el jugador no este insertado.
		MODIFICA La lista de jugadores
		EFECTOS Recorre la lista para buscar si ya esta ese dni en los jugadores y si
					acierto=0 introduce al nuevo jugador al final de la lista
					acierto=1 no introduce al jugador y muestra un aviso
		DESCRIPCION Añade un jugador a la lista comprobando si ya esta metido ese dni	*/

		void addJugador( Jugador jug);

	/*	PROC deleteJugador(Jugador jug) DEV int acierto (1 si se ha borrado el jugador
															-1 si la lista esta vacia
															-2 si no se ha encontrado el jugador)
		REQUIERE True
		MODIFICA 0
		EFECTOS Recoge el dni del jugador y llama a la funcion deleteJugador(string dni)
		DESCRIPCION Elimina un jugador de la lista comprobando si la lista esta vacia o si no existe el jugador	*/

		int deleteJugador( Jugador jug);

		/*	PROC deleteJugador(string dni) DEV int acierto (1 si se ha borrado el jugador
															-1 si la lista esta vacia
															-2 si no se ha encontrado el jugador)
			REQUIERE Que la lista no este vacia, y que el jugador (dni) este en la lista
			MODIFICA La variable acierto
			EFECTOS Borra el elemento del jugador de la lista<Jugadores> con ese dni
			DESCRIPCION Elimina un jugador de la lista comprobando si la lista esta vacia o si no existe el jugador por dni		*/

		int deleteJugador( string dni);


		/*	PROC escribeJugadores() DEV nada
			REQUIERE True
			MODIFICA El fichero jugadores.txt
			EFECTOS Imprime los jugadores de la lista en el fichero,
			sin vaciar la lista una vez almacenados
				Si no existe el fichero lo crea, y si existe lo reemplaza. 
			DESCRIPCION Escribe los jugadores en el fichero y no vacia la lista de elementos	*/

		void escribeJugadores();


		/*	PROC leeJugadores DEV nada
			REQUIERE Que exista el fichero jugadores.txt
			MODIFICA 0
			EFECTOS Vacia la lista y comprueba si esta lista, 
					despues vuelca los datos del fichero en la lista sin modificar el fichero(solo lectura).
			DESCRIPCION Lee los jugadores del fichero y los mete en la lista jugadores		*/

		void leeJugadores();

		/*	PROC giraRuleta() DEV nada
			REQUIERE True
			MODIFICA El valor de bola_
			EFECTOS Asigna un valor aleatorio para la bola entre 0 y 36.	
			DESCRIPCION Simula el giro de la ruleta	*/

		void giraRuleta();

		/*	PROC getPremios() DEV nada
			REQUIERE Lista de jugadores no este vacia
					 Lista de apuestas de cada jugador no este vacia

			MODIFICA El valor del dinero de la banca y el dinero de cada jugador
			EFECTOS Se modifica el dinero de cada jugador en funcion del tipo de apuesta, 
					el valor de la apuesta y la cantidad de dinero apostado.
					
			DESCRIPCION Funcion que asigna premios a los jugadores.
			*/


		void getPremios();

		/*	PROC imprimeJugadores() DEV bool (comprueba que no hay errores y hay jugadores)
			REQUIERE Que la lista no este vacia
			MODIFICA 0
			EFECTOS El interador de la lista recorre la lista y muestra por pantalla las caracteristicas de cada jugador.
			DESCRIPCION Imprime la  lista de jugadores por pantalla, devolviendo 0 si esta vacia y 1 si se ha podido imprimir	*/

		bool imprimeJugadores();

		/* 	PROC color(const int &bola) DEV string color
			REQUIERE La bola tenga un numero asignado
			MODIFICA 0
			EFECTOS Compara el valor de la bola y segun el numero que sea se le asigna string "negro" o "rojo" a la variable color.
			DESCRIPCION Devuelve un valor de color segun la bola*/

		string color(const int &bola);

		void getEstadoRuleta(int &jugadores, int &dinero, int &lanzamientos, int &ganancia);

};


#endif
