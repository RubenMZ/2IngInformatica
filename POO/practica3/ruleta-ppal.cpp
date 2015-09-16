#include"ruleta.h"
#include"jugador.h"
#include"crupier.h"
#include<iostream>
#include <unistd.h>

using namespace std;


int main(){


	Crupier c("46068656R", "12345");
	Ruleta r (c);
	Jugador j1("213124x", "1");
	Jugador j2("132432y", "2");
	Jugador j3("213124z", "3");
	Jugador j4("132432t", "4");
	int var;

	cout<<"La banca tiene "<<r.getBanca()<<" y con bola "<<r.getBola()<<endl;
	Crupier h = r.getCrupier();
	
	cout<<"Crupier "<<h.getDNI()<<" y codigo "<<h.getCodigoCrupier()<<endl;


	r.addJugador(j1);
	cout<<"Añadido jugador1\n";
	r.addJugador(j2);
	cout<<"Añadido jugador2\n";
	r.addJugador(j3);
	cout<<"Añadido jugador3\n";
	r.addJugador(j4);
	cout<<"Añadido jugador4\n";


	cout<<"Va a escribir jugadores\n";
	r.escribeJugadores();
	cout<<"Se escribieron jugadores\n";

	r.giraRuleta();

	r.leeJugadores();

	r.imprimeJugadores();

	cout<<"La bola es "<<r.getBola();
	r.getPremios();

	r.imprimeJugadores();

	r.escribeJugadores();

	

	return(0);
}
