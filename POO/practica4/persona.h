#ifndef PERSONA_H
#define PERSONA_H

#include <string>

using namespace std;


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



#endif
