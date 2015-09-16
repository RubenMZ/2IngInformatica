#include"crupier.h"
#include"persona.h"
#include<string>

using namespace std;

		/*Constructor*/
		Crupier::Crupier(string DNI, string codigoCrupier, string nombre, string apellidos, string direccion, string localidad, string provincia, string pais):Persona(DNI){

		setDNI(DNI);
		setCodigoCrupier(codigoCrupier);
		setNombre(nombre);
		setApellidos(apellidos);
		setDireccion(direccion);
		setLocalidad(localidad);
		setProvincia(provincia);
		setPais(pais);


		}

	
		/*Observadores*/
		string Crupier::getCodigoCrupier(){return(codigoCrupier_);}

		/*Modificadores*/
		void Crupier::setCodigoCrupier(string code){
			codigoCrupier_=code;	
		}
		
