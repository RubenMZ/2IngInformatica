#include <string>
#include <iostream>
#include "persona.h"

using namespace std;

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
