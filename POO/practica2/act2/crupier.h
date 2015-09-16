#ifndef CRUPIER_H
#define CRUPIER_H

#include <string>
#include "persona.h"

using namespace std;

class Crupier:public Persona{

	private:
		string codigoCrupier_;

	public:

		/*Constructor*/
		Crupier(string DNI, string codigoCrupier, string nombre="", string apellidos="", string direccion="", string localidad="", string provincia="", string pais="");

	
		/*Observadores*/
		string getCodigoCrupier();

		/*Modificadores*/
		void setCodigoCrupier(string code);
		


};


#endif
