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
		Crupier(const string &DNI, const string &codigoCrupier, const string &nombre="", const string &apellidos="", const string &direccion="", const string &localidad="", const string &provincia="", const string &pais=""):Persona(DNI, nombre, apellidos, direccion, localidad, provincia, pais){setCodigoCrupier(codigoCrupier);};


		/*Observadores*/
		inline string getCodigoCrupier(){return(codigoCrupier_);};

		/*Modificadores*/
		inline void setCodigoCrupier(const string &code){codigoCrupier_=code;};
		


};


#endif
