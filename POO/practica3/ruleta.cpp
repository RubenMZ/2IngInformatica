#include"ruleta.h"
#include <iostream>
#include <fstream>
#include"crupier.h"
#include"jugador.h"
#include <cstdlib>
#include <ctime>

using namespace std;

		/*Constructor*/
		Ruleta::Ruleta(Crupier c):crupier_(c){
			bola_=-1;
			banca_=1000000;
		}

		/*Modificadores*/		

		void Ruleta::setBanca(int num){
			if(num>0)
				banca_=num;
			else
				cout<<"ERROR. Solo valores positivos para la banca\n";
		}

		void Ruleta::setBola(int num){
			if((num>=0)&&(num<=36)){
				bola_=num;
			}else{
				cout<<"ERROR. Solo valores 0-36 para la bola\n";
			}

		}

		void Ruleta::setCrupier(Crupier crup){
			crupier_=crup;
		}

		/*Observadores*/

			//Ya declarados inline en el .h

		/***************************************METODOS*****************************************/


		/*	Añade un jugador a la lista comprobando si ya esta metido ese dni	*/

		void Ruleta::addJugador(Jugador jug){

			string dni=jug.getDNI();
			list<Jugador> listaca;
			Jugador aux("44XX", "1234");
			int acierto=0;

			while(!jugadores_.empty()){
					aux = jugadores_.back();
					jugadores_.pop_back();

					if(dni!=aux.getDNI()){
						listaca.push_back(aux);
					}else{
						listaca.push_back(aux);
						acierto=1;
					}
			}

			while(!listaca.empty()){
					aux = listaca.back();
					listaca.pop_back();
					jugadores_.push_back(aux);
			}

			if(acierto==1){
				cout<<"ERROR. El jugador con dni  ya esta insertado.\n\n";
			}else{
				jugadores_.push_back(jug);
			}

			fstream file;
			file.open((jug.getDNI()+".txt").c_str(), ios::app);
			file.close();
		}

		/*	Elimina un jugador de la lista comprobando si la lista esta vacia o si no existe el jugador	*/

		int Ruleta::deleteJugador(Jugador jug){

			string dni=jug.getDNI();
			return(deleteJugador(dni));

		}

		/*	Elimina un jugador de la lista comprobando si la lista esta vacia o si no existe el jugador por dni		*/

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

		/*	Escribe los jugadores en el fichero y vacía la lista de elementos	*/

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

		/*	Lee los jugadores del fichero y los mete en la lista jugadores		*/

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

		/*	Simula el giro de la ruleta y la obtención de un número aleatorio entre 0 y 36.		*/

		void Ruleta::giraRuleta(){

			srand(time(NULL));
			setBola(rand()%37);

		}


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

		/*Devuelve un valor de color segun la bola*/
		string Ruleta::color(int bola){
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

		/*	Imprime la  lista de jugadores por pantalla, devolviendo 0 si esta vacia y 1 si se ha podido imprimir	*/

		int Ruleta::imprimeJugadores(){
			Jugador aux("44XX", "1234");
			list<Jugador>listaca;

			if(jugadores_.empty()){
				cout<<"Lista vacia, no se pueden imprimir jugadores\n";
				return 0;
			}

			while(!jugadores_.empty()){
				aux = jugadores_.back();
				jugadores_.pop_back();
				cout<<"DNI: "<<aux.getDNI()<<", codigo: "<<aux.getCodigoJugador()<<", nombre: "<<aux.getNombre()<<", apellidos: "<<aux.getApellidos()<<", "<<aux.getDireccion()<<", localidad: "<<aux.getLocalidad()<<", provincia: "<<aux.getProvincia()<<", pais: "<<aux.getPais()<<", dinero: "<<aux.getDinero()<<endl;
				listaca.push_back(aux);
			}

			while(!listaca.empty()){
					aux = listaca.back();
					listaca.pop_back();
					jugadores_.push_back(aux);
			}

			return 1;

		}






