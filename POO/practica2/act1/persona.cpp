#include<string>
#include"persona.h"

using namespace std;

/*Constructor*/
		
		Persona::Persona(string DNI, string nombre, string apellidos, string direccion, string localidad, string provincia, string pais){

		DNI_=DNI; 
		nombre_=nombre; 
		apellidos_=apellidos;
		direccion_=direccion;
		localidad_=localidad; 
		provincia_=provincia; 
		pais_=pais;
	
}

		/*Modificadores*/

		void Persona::setDNI(string num){
			DNI_=num;
		}
		
		void Persona::setNombre(string name){
			nombre_=name;
		}
	
		void Persona::setApellidos(string names){
			apellidos_=names;
		}
	
		void Persona::setDireccion(string adress){
			direccion_=adress;
		}
		void Persona::setLocalidad(string town){
			localidad_=town;
		}

		void Persona::setProvincia(string city){
			provincia_=city;
		}

		void Persona::setPais(string pay){
			pais_=pay;
		}

		/*Observadores*/
		string Persona::getDNI(){return(DNI_);}
		string Persona::getNombre(){return(nombre_);}
		string Persona::getApellidos(){return(apellidos_);}
		string Persona::getDireccion(){return(direccion_);}
		string Persona::getLocalidad(){return(localidad_);}
		string Persona::getProvincia(){return(provincia_);}
		string Persona::getPais(){return(pais_);}
		string Persona::getApellidosyNombre(){
	
			string cadena;

			cadena = apellidos_+", "+nombre_;

			return (cadena);
		}
