/**
@file clave.hpp
@brief Fichero para la clase clave del arbol
@author Ruben
*/

#ifndef CLAVE_H
#define CLAVE_H

#include <iostream>
#include <fstream>

using namespace std;

namespace edi{
/** 
	@brief Define las claves del arbol para identificar los elementos de la lista
*/
class Clave{

private:
	int dni_; //!< Clave, dni de la persona
	int posicion_; //!< Posicion del dni en la lista

public:
	
	//* @name CONSTRUCTORES

	/**
		@fn Clave (const int & dni, const int &pos);
		@brief Constructor completo de la clave
		@param  int dni
		@param int pos
	*/
	Clave (const int & dni, const int &pos);

	/**
		@fn Clave ();
		@brief Constructor sin parametros de la clave
	*/
	Clave ();

	/**
		@fn Clave (const Clave & c);
		@brief Constructor de copia
		@param  Clave c
	*/
	Clave (const Clave & c);

	//* @name MODIFICADORES

	/**
		@fn void setDni(const int & num);
		@brief Modificador de dni
		@param  int num
		@return void
	*/
	void setDni(const int & num);

	/**
		@fn void setPosicion(const int & pos);
		@brief Modificador de posicion
		@param  int pos
		@return void
	*/
	void setPosicion(const int & pos);

	//* @name OBSERVADORES

	/**
		@fn int getDni()const;
		@brief Observador dni
		@return int dni
	*/
	int getDni()const;

	/**
		@fn int getPosicion()const;
		@brief Observador posicion
		@return int posicion
	*/
	int getPosicion()const;

	//* @name OPERADORES

	/**
		@fn Clave & operator=(const Clave & c);
		@brief Iguala los valores de la clave pasada como parametro
		@param Clave c
		@return Clave aux
	*/
	Clave & operator=(const Clave & c);

	/**
		@fn bool operator>(const Clave & c)const;
		@brief Compara si el dni de la clave es mayor que clave c
		@param Clave c
		@return bool de la comparacion >
	*/
	bool operator>(const Clave & c)const;
	
	/**
		@fn bool operator<(const Clave & c)const;
		@brief Compara si el dni de la clave es menor que la clave c
		@param Clave c
		@return bool de la comparacion <
	*/
	bool operator<(const Clave & c)const;
	
	/**
		@fn bool operator==(const Clave & c)const;
		@brief Compara si el dni de la clave es igual a la clave c
		@param Clave c
		@return bool de la comparacion ==
	*/
	bool operator==(const Clave & c)const;
	
	/**
		@fn bool operator>=(const Clave & c)const;
		@brief Compara si el dni de la clave es mayor o igual que la clave c
		@param Clave c
		@return bool de la comparacion >=
	*/
	bool operator>=(const Clave & c)const;
	
	/**
		@fn bool operator<=(const Clave & c)const;
		@brief Compara si el dni de la clave es menor o igual que la clave c
		@param Clave c
		@return bool de la comparacion <=
	*/
	bool operator<=(const Clave & c)const;

	/**
		@fn friend ostream & operator<<(ostream &stream, const Persona &p);
		@brief Muestra por pantalla la clave c
		@param Clave c
		@param ostream stream
		@return ostream Flujo de salida <<
	*/

	friend ostream & operator<<(ostream &stream, const Clave &c);

	/**
		@fn friend istream & operator>>(istream &stream, Clave &c);
		@brief Pide los datos de la clave 
		@param Clave c
		@param istream stream
		@return istream Flujo de entrada >>
	*/

	friend istream & operator>>(istream &stream, Clave &c);

	/**
		@fn friend ofstream & operator<<(ofstream &stream, const Clave &c);
		@brief Escribe el flujo en el fichero stream
		@param Clave c
		@param ofstream stream
		@return ofstream Flujo de salida <<
	*/

	friend ofstream & operator<<(ofstream &stream, const Clave &c);

	/**
		@fn friend ifstream & operator>>(ifstream &stream, Clave &c);
		@brief Lee el flujo del fichero stream
		@param Clave c
		@param ifstream stream
		@return ifstream Flujo de entrada >>
	*/

	friend ifstream & operator>>(ifstream &stream,  Clave &c);



};

}

#endif