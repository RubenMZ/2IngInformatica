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
		Crupier(string DNI, string codigoCrupier, string nombre="", string apellidos="", string direccion="", string localidad="", string provincia="", string pais=""):Persona(DNI, nombre, apellidos, direccion, localidad, provincia, pais){setCodigoCrupier(codigoCrupier);};


		/*Observadores*/
		inline string getCodigoCrupier(){return(codigoCrupier_);};

		/*Modificadores*/
		inline void setCodigoCrupier(string code){codigoCrupier_=code;};
		


};


#endif
