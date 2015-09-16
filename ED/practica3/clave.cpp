/**
@file clave.cpp
@brief Fichero de la implementacion de las funciones de clase Clave
@author Ruben
*/

#include "clave.hpp"
#include <cstdlib>

using namespace edi;

//* @name CONSTRUCTORES

	/**
		@fn Clave (const int & dni, const int &pos);
		@brief Constructor completo de la clave
		@param  int dni
		@param int pos
	*/
	Clave::Clave (const int & dni, const int &pos){
		dni_=dni;
		posicion_=pos;
	}

	/**
		@fn Clave ();
		@brief Constructor sin parametros de la clave
	*/
	Clave::Clave (){

	}

	/**
		@fn Clave (const Clave & c);
		@brief Constructor de copia
		@param  Clave c
	*/
	Clave::Clave (const Clave & c){
		dni_=c.getDni();
		posicion_=c.getPosicion();
	}

	//* @name MODIFICADORES

	/**
		@fn void setDni(const int & num);
		@brief Modificador de dni
		@param  int num
		@return void
	*/
	void Clave::setDni(const int & num){
		dni_=num;
	}

	/**
		@fn void setPosicion(const int & pos);
		@brief Modificador de posicion
		@param  int pos
		@return void
	*/
	void Clave::setPosicion(const int & pos){
		posicion_=pos;
	}

	//* @name OBSERVADORES

	/**
		@fn int getDni()const;
		@brief Observador dni
		@return int dni
	*/
	int Clave::getDni()const{
		return(dni_);
	}

	/**
		@fn int getPosicion()const;
		@brief Observador posicion
		@return int posicion
	*/
	int Clave::getPosicion()const{
		return(posicion_);
	}

	//* @name OPERADORES

	/**
		@fn Clave & operator=(const Clave & c);
		@brief Iguala los valores de la clave pasada como parametro
		@param Clave c
		@return Clave aux
	*/
	Clave & Clave::operator=(const Clave & c){
		if(this!=&c){
			setDni(c.getDni());
			setPosicion(c.getPosicion());
		}
		return(*this);
	}

	/**
		@fn bool operator>(const Clave & c)const;
		@brief Compara si el dni de la clave es mayor que clave c
		@param Clave c
		@return bool de la comparacion >
	*/
	bool Clave::operator>(const Clave & c)const{
		return(getDni()>c.getDni());
	}
	
	/**
		@fn bool operator<(const Clave & c)const;
		@brief Compara si el dni de la clave es menor que la clave c
		@param Clave c
		@return bool de la comparacion <
	*/
	bool Clave::operator<(const Clave & c)const{
		return(getDni()<c.getDni());
	}
	
	/**
		@fn bool operator==(const Clave & c)const;
		@brief Compara si el dni de la clave es igual a la clave c
		@param Clave c
		@return bool de la comparacion ==
	*/
	bool Clave::operator==(const Clave & c)const{
		return(getDni()==c.getDni());
	}
	
	/**
		@fn bool operator>=(const Clave & c)const;
		@brief Compara si el dni de la clave es mayor o igual que la clave c
		@param Clave c
		@return bool de la comparacion >=
	*/
	bool Clave::operator>=(const Clave & c)const{
		return(getDni()>=c.getDni());
	}
	
	/**
		@fn bool operator<=(const Clave & c)const;
		@brief Compara si el dni de la clave es menor o igual que la clave c
		@param Clave c
		@return bool de la comparacion <=
	*/
	bool Clave::operator<=(const Clave & c)const{
		return(getDni()<=c.getDni());
	}

	namespace edi{

		/**
		@fn ostream & operator<<(ostream &stream, const Persona &p);
		@brief Muestra por pantalla la clave c
		@param Clave c
		@param ostream stream
		@return ostream Flujo de salida <<
	*/

	ostream & operator<<(ostream &stream, const Clave &c){
		stream<<"Clave con valor "<<c.getDni()<<" en posicion "<<c.getPosicion()<<endl;
		return(stream);
	}

	/**
		@fn istream & operator>>(istream &stream, Clave &c);
		@brief Pide los datos de la clave 
		@param Clave c
		@param istream stream
		@return istream Flujo de entrada >>
	*/

	istream & operator>>(istream &stream, Clave &c){
		int var;
		cout<<"Dni: ";
		stream>>var;
		c.setDni(var);
		cout<<"Posicion: ";
		stream>>var;
		c.setPosicion(var);

		return(stream);
	}

	/**
		@fn ofstream & operator<<(ofstream &stream, const Clave &c);
		@brief Escribe el flujo en el fichero stream
		@param Clave c
		@param ofstream stream
		@return ofstream Flujo de salida <<
	*/

	ofstream & operator<<(ofstream &stream, const Clave &c){
		stream<<c.getDni()<<","<<c.getPosicion();
		return(stream);
	}

	/**
		@fn ifstream & operator>>(ifstream &stream, Clave &c);
		@brief Lee el flujo del fichero stream
		@param Clave c
		@param ifstream stream
		@return ifstream Flujo de entrada >>
	*/

	ifstream & operator>>(ifstream &stream, Clave &c){

		char aux[30];

		stream.getline(aux,30, ',');//dni
		c.setDni(atoi(aux));
		stream.getline(aux,30, '\n');//posicion
		c.setPosicion(atoi(aux));

		return stream;
	}

}//namespace