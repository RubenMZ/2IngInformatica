#ifndef NAMESPACE_H
#define NAMESPACE_H


#include <iostream>
#include <string>
#include <fstream>
#include <cstdio>
#include <list>
#include <cstdlib>
#include <ctime>

using namespace std;


namespace ruleta{

// PERSONA.H


class Persona{

	private:
		string DNI_, nombre_, apellidos_, direccion_, localidad_, provincia_, pais_;
	
	public:
		/*Constructor*/
		
		Persona(const string &DNI, const string &nombre="", const string &apellidos="", const string &direccion="", const string &localidad="", const string &provincia="", const string &pais="");

		/*Modificadores*/

		inline void setDNI(const string num){DNI_=num;};
		inline void setNombre(const string name){nombre_=name;};
		inline void setApellidos(const string names){apellidos_=names;};
		inline void setDireccion(const string adress){direccion_=adress;};
		inline void setLocalidad(const string town){localidad_=town;};
		inline void setProvincia(const string city){provincia_=city;};
		inline void setPais(const string pay){pais_=pay;};

		/*Observadores*/
		inline string getDNI(){return(DNI_);};
		inline string getNombre(){return(nombre_);};
		inline string getApellidos(){return(apellidos_);};
		inline string getDireccion(){return(direccion_);};
		inline string getLocalidad(){return(localidad_);};
		inline string getProvincia(){return(provincia_);};
		inline string getPais(){return(pais_);};
		string getApellidosyNombre();




};


//PERSONA.CPP

/*Constructor*/
		
		Persona::Persona(const string &DNI, const string &nombre, const string &apellidos, const string &direccion, const string &localidad, const string &provincia, const string &pais){

		setDNI(DNI); 
		setNombre(nombre); 
		setApellidos(apellidos);
		setDireccion(direccion);
		setLocalidad(localidad); 
		setProvincia(provincia);
		setPais(pais);
	
		}

		/*Modificadores, inline en .h*/
		/*Observadores, inline en .h*/


		string Persona::getApellidosyNombre(){
	
			string cadena;

			cadena = apellidos_+", "+nombre_;

			return (cadena);
		}




// CRUPIER.H

class Crupier:public Persona{

	private:
		string codigoCrupier_;

	public:

		/*Constructor*/
		Crupier(const string &DNI, const string &codigoCrupier, const string &nombre="", const string &apellidos="", const string &direccion="", const string &localidad="", const string &provincia="", const string &pais=""):Persona(DNI, nombre, apellidos, direccion, localidad, provincia, pais){setCodigoCrupier(codigoCrupier);};


		/*Observadores*/
		inline string getCodigoCrupier(){return(codigoCrupier_);};

		/*Modificadores*/
		inline void setCodigoCrupier(const string &code){codigoCrupier_=code;};
		


};

// JUGADOR.H


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
		Jugador(const string DNI, const string &codigoJugador, const string &nombre="", const string &apellidos="", const string &direccion="", const string &localidad="", const string &provincia="", const string &pais=""):Persona(DNI, nombre, apellidos, direccion, localidad, provincia, pais), codigoJugador_(codigoJugador){dinero_=1000;}; //codigo_(codigo) le asigna al campo codigo_ el parametro codigo

		/*Modificadores*/
		inline void setCodigoJugador(const string &code){codigoJugador_=code;};
		inline void setDinero(const int &num){dinero_=num;};

		/*Observadores*/
		inline int getDinero(){return(dinero_);};
		inline string getCodigoJugador(){return(codigoJugador_);};
		

		/*METODOS*/

		/*PROC setApuestas() DEV nada
		REQUIERE Que exista el fichero de apuesta del jugador creado
		MODIFICA La lista de apuestas del jugador
		EFECTOS Abre un fichero DNI.txt y modifica la lista de apuestas de jugador
		DESCRIPCION Abre el fichero numDNI.txt del jugador y copia las apuestas del fichero en su lista de apuestas,
					añadiendo al final de la lista cada apuesta que el jugador haya colocado en el fichero (cada linea)
					*/

		inline list<apuesta> getApuestas(){return(apuestas_);};
		void setApuestas();
};


//JUGADOR.CPP


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


//RULETA.H

class Ruleta{

	private:/*CAMPOS*/
		int banca_, bola_;
		Crupier crupier_;
		list<Jugador> jugadores_;
	public:
		/*Constructor*/
		Ruleta(const Crupier &c);

		/*Modificadores*/		

		void setBanca(const int &num);
		void setBola(const int &num);
		inline void setCrupier(const Crupier &crup){crupier_=crup;};

		/*Observadores*/

		inline int getBanca(){return(banca_);};
		inline int getBola(){return(bola_);};
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

};


//RULETA.CPP

	/*Constructor*/
		Ruleta::Ruleta(const Crupier &c):crupier_(c){
			bola_=-1;
			banca_=1000000;
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

			srand(time(NULL));
			setBola(rand()%37);

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

}


#endif