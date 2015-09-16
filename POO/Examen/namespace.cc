/**
@file namespace.cc
@brief Fichero con algunas funciones
@author Ruben
@date hoy
*/

#include "namespace.h"
#include <string>

using namespace std;


namespace Figura{
	

/**
@fn double Cuadrado::area()
@brief Devuelve el area del cuadrado
@param ninguno
@param puesnah
@return lado*lado
*/
	double Cuadrado::area(){
		return(lado_*lado_);
	}

	double Cuadrado::perimetro(){
		return(lado_*4);
	}

		double Circulo::area(){
		return(PI_* radio_ * radio_);
	}

	double Circulo::perimetro(){
		return(2*PI_*radio_);
	}


}