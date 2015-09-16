#include "persona.h"
#include "jugador.h"
#include <iostream>
#include <fstream>
#include <string>
#include <cstdlib>
#include <cstdio>


using namespace std;


		/*Constructor, inline en .h*/
		/*Observadores, inline en .h*/
		/*Modificadores, inline en .h*/

		/*METODOS*/


		/*	
		PROC setApuestas() DEV nada
		REQUIERE Que exista el fichero de apuesta del jugador creado
		MODIFICA La lista de apuestas del jugador
		EFECTOS Abre un fichero DNI.txt y modifica la lista de apuestas de jugador
		DESCRIPCION Abre el fichero numDNI.txt del jugador y copia las apuestas del fichero en su lista de apuestas,
					añadiendo al final de la lista cada apuesta que el jugador haya colocado en el fichero (cada linea)
					*/
	
		void Jugador::setApuestas(){

			apuesta x;
			char line[50];
			
			ifstream fichero;

			fichero.open((getDNI()+".txt").c_str());

			if(fichero.is_open()){

				while((fichero.getline(line, 50,','))){
					
					x.tipoApuesta=atoi(line);

					fichero.getline(line, 50,',');
					x.valorApuesta=line;

					fichero.getline(line, 50,'\n');
					x.cantApuesta=atoi(line);
					apuestas_.push_back(x);

				}

			}else{
				cout<<"El fichero "<<getDNI()<<".txt no pudo abrirse."<<"\n";
			}	
			
			fichero.close();

		}
