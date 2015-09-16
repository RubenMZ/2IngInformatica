#include<iostream>
#include<string>
#include<list>
#include"persona.h"
#include"jugador.h"

using namespace std;


int main(){

	Jugador j("44XX", "1234");

	list<apuestas> lista;
	apuestas elem;


	cout<<"Soy el jugador con dni: "<<j.getDNI()<<" y con codigo: "<<j.getCodigoJugador()<<"\n"; 

	j.setCodigoJugador("2222");

	cout<<"Soy el jugador con dni: "<<j.getDNI()<<" y con codigo: "<<j.getCodigoJugador()<<"\n"; 

	j.setApuestas();
	lista = j.getApuestas();
	
	cout<<"Las apuestas para el jugador con dni: "<<j.getDNI()<<" y con codigo: "<<j.getCodigoJugador()<<"\n"; 

	while(lista.empty()==false){
		elem=lista.front();
		cout<<elem.tipoApuesta<<","<<elem.valorApuesta<<","<<elem.cantApuesta<<"\n";
		lista.pop_front();
	}

	

	return 0;
}