 /**
@file principal.cpp
@brief Fichero del programa principal para calcular el error de la aproximacion
@author Ruben Medina
@date 23-02-15
@version 1.0
 */

#include "Punto2D.h"
#include "funciones.h"
#include "Recta2D.h"
#include <iostream>
#include <vector>
#include <cstring>
#include <string>

using namespace std;


/**
@main Programa principal
@brief Realizar llamadas a las funciones cargarContorno, cargarAproximacion y calcularError
*/

int main(){

	vector< Punto2D<double> > contorno;
	vector<int> aproximacion;
	double resultado;
	string cad1 = "abrelatas.txt";
	string cad2 = "aproximacion.txt";

	cout<<"Introduce el nombre del fichero de los puntos: ";
	cin>>cad1;
	cout<<"Introduce el nombre del fichero con la aproximacion: ";
	cin>>cad2;

	cargarContorno(contorno, cad1.c_str());
	cargarAproximacionPoligonal( aproximacion , cad2.c_str());


	resultado = calcularError(contorno, aproximacion);

	cout<<"El error es: "<<resultado<<endl;

	return 0;
}
