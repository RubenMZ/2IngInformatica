#include"persona.h"
#include"jugador.h"
#include<iostream>
#include<fstream>
#include<string>
#include<cstdlib>
#include<cstdio>


using namespace std;


		Jugador::Jugador(string DNI, string codigoJugador, string nombre, string apellidos, string direccion, string localidad, string provincia, string pais, int dinero):Persona(DNI){
		setDNI(DNI);
		setCodigoJugador(codigoJugador);
		setDinero(dinero);
		setNombre(nombre);
		setApellidos(apellidos);
		setDireccion(direccion);
		setLocalidad(localidad);
		setProvincia(provincia);
		setPais(pais);
		
		}

		/*Modificadores*/
		void Jugador::setCodigoJugador(string code){

			codigoJugador_=code;
		}
		void Jugador::setDinero(int num){
			dinero_=num;
		}
	
		

		/*METODOS*/
		
		void Jugador::setApuestas(){

			apuestas x;
			char line[50];
			
			ifstream fichero;

			fichero.open((getDNI()+".txt").c_str());



		

			if(fichero.is_open()){

				cout<<"Fichero abierto"<<endl;

				while((fichero.getline(line, 50,','))){
					


					
					x.tipoApuesta=atoi(line);

					fichero.getline(line, 50,',');
					x.valorApuesta=line;

					fichero.getline(line, 50,',');
					x.cantApuesta=atoi(line);
					(apuestas_).push_back(x);

				}

			}else{
				cout<<"El fichero "<<getDNI()<<".txt no pudo abrirse."<<"\n";
			}	
			
			fichero.close();

		}
