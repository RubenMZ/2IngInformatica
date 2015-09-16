#ifndef PERSONA_H
#define PERSONA_H

#include<string>

using namespace std;


class Persona{

	private:
		string DNI_, nombre_, apellidos_, direccion_, localidad_, provincia_, pais_;
	
	public:
		/*Constructor*/
		
		Persona(string DNI, string nombre="", string apellidos="", string direccion="", string localidad="", string provincia="", string pais="");

		/*Modificadores*/

		void setDNI(string num);
		void setNombre(string name);
		void setApellidos(string names);
		void setDireccion(string adress);
		void setLocalidad(string town);
		void setProvincia(string city);
		void setPais(string pay);

		/*Observadores*/
		string getDNI();
		string getNombre();
		string getApellidos();
		string getDireccion();
		string getLocalidad();
		string getProvincia();
		string getPais();
		string getApellidosyNombre();




};



#endif
