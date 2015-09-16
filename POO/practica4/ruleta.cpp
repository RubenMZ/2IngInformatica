#include "ruleta.h"
#include <iostream>
#include <fstream>
#include "crupier.h"
#include "jugador.h"
#include <cstdlib>
#include <ctime>

using namespace std;

		/*Constructor*/
		Ruleta::Ruleta(const Crupier &c):crupier_(c){
			bola_=-1;
			banca_=1000000;
			lanzamientos_=0;
		}

		/*Modificadores*/		

		void Ruleta::setBanca(const int &num){
			if(num>0)
				banca_=num;
			else
				cout<<"ERROR. Solo valores positivos para la banca\n";
		}

		void Ruleta::setBola(const int &num){
			if((num>=0)&&(num<=36)){
				bola_=num;
			}else{
				cout<<"ERROR. Solo valores 0-36 para la bola\n";
			}

		}


		/*Observadores*/

			//Ya declarados inline en el .h

		/***************************************METODOS*****************************************/


		/*	
		PROC addJugador(Jugador jug) DEV nada
		REQUIERE Que el jugador no este insertado.
		MODIFICA La lista de jugadores
		EFECTOS Recorre la lista para buscar si ya esta ese dni en los jugadores y si
					acierto=0 introduce al nuevo jugador al final de la lista
					acierto=1 no introduce al jugador y muestra un aviso
		DESCRIPCION Añade un jugador a la lista comprobando si ya esta metido ese dni	*/

		void Ruleta::addJugador(Jugador jug){

			string dni=jug.getDNI();
			list<Jugador>::iterator i;
			int acierto=0;

			if(!jugadores_.empty()){
				for(i=jugadores_.begin(); i!=jugadores_.end(); i++){
					if(dni==i->getDNI())
						acierto=1;
					if(acierto==1)
						break;
				}
			}

			if(acierto==1){
				cout<<"ERROR. El jugador con dni ya esta insertado."<<endl<<endl;
			}else{
				jugadores_.push_back(jug);
			}

			fstream file;
			file.open((jug.getDNI()+".txt").c_str(), ios::app);
			file.close();
		}

		/*	PROC deleteJugador(Jugador jug) DEV int acierto (1 si se ha borrado el jugador
															-1 si la lista esta vacia
															-2 si no se ha encontrado el jugador)
			REQUIERE True
			MODIFICA 0
			EFECTOS Recoge el dni del jugador y llama a la funcion deleteJugador(string dni)
			DESCRIPCION Elimina un jugador de la lista comprobando si la lista esta vacia o si no existe el jugador	*/

		int Ruleta::deleteJugador(Jugador jug){

			string dni=jug.getDNI();
			return(deleteJugador(dni));

		}

		/*	PROC deleteJugador(string dni) DEV int acierto (1 si se ha borrado el jugador
															-1 si la lista esta vacia
															-2 si no se ha encontrado el jugador)
			REQUIERE Que la lista no este vacia, y que el jugador (dni) este en la lista
			MODIFICA La variable acierto
			EFECTOS Borra el elemento del jugador de la lista<Jugadores> con ese dni
			DESCRIPCION Elimina un jugador de la lista comprobando si la lista esta vacia o si no existe el jugador por dni		*/

		int Ruleta::deleteJugador(string dni){

			int acierto=-2;
			list<Jugador>listaca;
			Jugador aux("44XX", "1234");

			if(jugadores_.empty()){
				acierto=-1;
			}else{
				while(!jugadores_.empty()){
					aux = jugadores_.back();
					jugadores_.pop_back();

					if(dni!=aux.getDNI()){
						listaca.push_back(aux);
					}else{
						acierto=1;
					}
				}

				while(!listaca.empty()){
					aux = listaca.back();
					listaca.pop_back();
					jugadores_.push_back(aux);
				}

			}

			return(acierto);
		}

		/*	PROC escribeJugadores() DEV nada
			REQUIERE True
			MODIFICA El fichero jugadores.txt
			EFECTOS Imprime los jugadores de la lista en el fichero,
			sin vaciar la lista una vez almacenados
				Si no existe el fichero lo crea, y si existe lo reemplaza. 
			DESCRIPCION Escribe los jugadores en el fichero y no vacia la lista de elementos	*/

		void Ruleta::escribeJugadores(){

			fstream fichero;
			fichero.open("jugadores.txt", ios::out);
			list<Jugador>::iterator i;


			if(!jugadores_.empty()){
				for(i=jugadores_.begin(); i!=jugadores_.end(); i++){
					fichero<<i->getDNI()<<","<<i->getCodigoJugador()<<","<<i->getNombre()<<","<<i->getApellidos()<<","<<i->getDireccion()<<","<<i->getLocalidad()<<","<<i->getProvincia()<<","<<i->getPais()<<","<<i->getDinero()<<endl;
				}
			}

			//jugadores_.clear();
			fichero.close();
		}

		/*	PROC leeJugadores DEV nada
			REQUIERE Que exista el fichero jugadores.txt
			MODIFICA 0
			EFECTOS Vacia la lista y comprueba si esta lista, 
					despues vuelca los datos del fichero en la lista sin modificar el fichero(solo lectura).
			DESCRIPCION Lee los jugadores del fichero y los mete en la lista jugadores		*/

		void Ruleta::leeJugadores(){
			fstream fichero;
			fichero.open("jugadores.txt", ios::in);
			Jugador aux("44XX", "1234");
			jugadores_.clear();
			char cadena[50];
			
			if(jugadores_.empty()){
				cout<<"Lista vacia y correcta para leer jugadores del fichero\n";
			}

			while(fichero.getline(cadena, 50, ',')){
				aux.setDNI(cadena);
				fichero.getline(cadena, 50, ',');
				aux.setCodigoJugador(cadena);
				fichero.getline(cadena, 50, ',');
				aux.setNombre(cadena);
				fichero.getline(cadena, 50, ',');
				aux.setApellidos(cadena);
				fichero.getline(cadena, 50, ',');
				aux.setDireccion(cadena);
				fichero.getline(cadena, 50, ',');
				aux.setLocalidad(cadena);
				fichero.getline(cadena, 50, ',');
				aux.setProvincia(cadena);
				fichero.getline(cadena, 50, ',');
				aux.setPais(cadena);
				fichero.getline(cadena, 50, '\n');
				aux.setDinero(atoi(cadena));

				jugadores_.push_back(aux);
			}
			
			fichero.close();
		}

		/*	PROC giraRuleta() DEV nada
			REQUIERE True
			MODIFICA El valor de bola_
			EFECTOS Asigna un valor aleatorio para la bola entre 0 y 36.	
			DESCRIPCION Simula el giro de la ruleta	*/

		void Ruleta::giraRuleta(){

			//int lanz;
			//lanz=getLanzamientos();
			srand(time(NULL));
			setBola(rand()%37);
			lanzamientos_++;
			//setLanzamientos(lanz);

		}

		/*	PROC getPremios() DEV nada
			REQUIERE Lista de jugadores no este vacia
					 Lista de apuestas de cada jugador no este vacia

			MODIFICA El valor del dinero de la banca y el dinero de cada jugador
			EFECTOS Se modifica el dinero de cada jugador en funcion del tipo de apuesta, 
					el valor de la apuesta y la cantidad de dinero apostado.

			DESCRIPCION Funcion que asigna premios a los jugadores.
			*/

		void Ruleta::getPremios(){

			Jugador jugAux("44XX", "1234");

			list<Jugador>::iterator j;
			list<apuesta>::iterator a;
			list<apuesta> la;
			string valorApu;


			for(j=jugadores_.begin(); j!=jugadores_.end(); j++){

				j->setApuestas();
				la=j->getApuestas();

				for(a=la.begin(); a!=la.end();a++){
					

					switch(a->tipoApuesta){

						case 1:	if((atoi((a->valorApuesta).c_str())==bola_)){
								j->setDinero(j->getDinero()+(a->cantApuesta*35));
								banca_-=a->cantApuesta*35;
							}else{
								j->setDinero(j->getDinero()-(a->cantApuesta));
								banca_+=a->cantApuesta;
							}
							break;

						case 2:	valorApu = color(bola_);

							if((a->valorApuesta==valorApu)&&(bola_!=0)){
								j->setDinero(j->getDinero()+(a->cantApuesta));
								banca_-=a->cantApuesta;
							}else{
								j->setDinero(j->getDinero()-(a->cantApuesta));
								banca_+=a->cantApuesta;
							}
							break;
						case 3:
							if(bola_%2==0){
								valorApu="par";
							}else{
								valorApu="impar";
							}

							if((a->valorApuesta==valorApu)&&(bola_!=0)){
								j->setDinero(j->getDinero()+(a->cantApuesta));
								banca_-=a->cantApuesta;
							}else{
								j->setDinero(j->getDinero()-(a->cantApuesta));
								banca_+=a->cantApuesta;
							}

							break;

						case 4:	if(bola_>0&&bola_<19){
								valorApu="bajo";
							}else{
								valorApu="alto";
							}

							if((a->valorApuesta==valorApu)&&(bola_!=0)){
								j->setDinero(j->getDinero()+(a->cantApuesta));
								banca_-=a->cantApuesta;
							}else{
								j->setDinero(j->getDinero()-(a->cantApuesta));
								banca_+=a->cantApuesta;
							}
							break;

						default: cout<<"Tipo apuesta no valida"<<endl;
							break;
					}
				}
			}
		}

		/* 	PROC color(const int &bola) DEV string color
			REQUIERE La bola tenga un numero asignado
			MODIFICA 0
			EFECTOS Compara el valor de la bola y segun el numero que sea se le asigna string "negro" o "rojo" a la variable color.
			DESCRIPCION Devuelve un valor de color segun la bola*/
		string Ruleta::color(const int &bola){
			string color;

			if(bola==0){
				cout<<"El numero cero no tiene color"<<endl;
				return("Ninguno");
			}

			if((bola>0&&bola<11)||(bola>18&&bola<29)){
				if(bola%2==0){
					color="negro";
				}else{
					color="rojo";
				}
			}else{
				if(bola%2==0){
					color="rojo";
				}else{
					color="negro";
				}
			}

			return (color);
		}

		/*	PROC imprimeJugadores() DEV bool (comprueba que no hay errores y hay jugadores)
			REQUIERE Que la lista no este vacia
			MODIFICA 0
			EFECTOS El interador de la lista recorre la lista y muestra por pantalla las caracteristicas de cada jugador.
			DESCRIPCION Imprime la  lista de jugadores por pantalla, devolviendo 0 si esta vacia y 1 si se ha podido imprimir	*/

		bool Ruleta::imprimeJugadores(){
			Jugador aux("44XX", "1234");
			list<Jugador>::iterator i;

			if(jugadores_.empty()){
				cout<<"Lista vacia, no se pueden imprimir jugadores\n";
				return false;
			}

			for(i=jugadores_.begin(); i!=jugadores_.end();i++)
				cout<<"DNI: "<<i->getDNI()<<", codigo: "<<i->getCodigoJugador()<<", nombre: "<<i->getNombre()<<", apellidos: "<<i->getApellidos()<<", "<<i->getDireccion()<<", localidad: "<<i->getLocalidad()<<", provincia: "<<i->getProvincia()<<", pais: "<<i->getPais()<<", dinero: "<<i->getDinero()<<endl;

			return true;

		}


		void Ruleta::getEstadoRuleta(int &jugadores, int &dinero, int &lanzamientos, int &ganancia){

			list<Jugador> aux = getJugadores();
			list<Jugador>::iterator i;
			jugadores=0;
			dinero=0;
			lanzamientos=0;
			ganancia = 0;


			for(i=aux.begin(); i!=aux.end(); i++){
				jugadores++;
				dinero += i->getDinero();
			}
			lanzamientos=getLanzamientos();
			dinero+=getBanca();
			ganancia = getBanca()-1000000;
		}






