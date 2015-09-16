 /**
@file funciones.cpp
@brief Fichero de funciones para implementar la funcionalidad y calcular el error
@author Ruben Medina
@date 23-02-15
@version 1.0
 */

#include "funciones.h"
#include <fstream>
#include <iostream>
#include <cstdlib>
#include <cmath>




using namespace std;

/**
@fn void cargarContorno(vector< Punto2D<T> > & contorno, const char * ficheroContorno )
@brief Carga el vector con los puntos del fichero
@pre contorno este vacio
@arg vector< Punto2D<T> > & contorno , vector de puntos de contorno
@arg char * ficheroContorno, nombre del fichero
@post contorno tenga elementos
@return void
*/

void cargarContorno(vector< Punto2D<double> > & contorno, const char * ficheroContorno ){

	fstream fichero;

	double x, y;

	assert( contorno.empty() );

	fichero.open(ficheroContorno, ios::in);
	
	while(fichero>>x>>y){
		Punto2D<double> p(x, y);
		contorno.push_back(p);
	}

	assert (!contorno.empty());

	fichero.close();
}

/**
@fn void cargarAproximacionPoligonal(vector<int> &aproximacionPoligonal, const char* ficheroAproximacionPoligonal)
@brief Carga el vector con los enteros del fichero
@pre aproximacionPoligonal este vacio
@arg vector<int> &aproximacionPoligonal, vector de enteros para indice de puntos
@arg const char* ficheroAproximacionPoligonal , nombre del fichero
@post aproximacionPoligonal tenga elementos
@return void
*/


void cargarAproximacionPoligonal(vector<int> &aproximacionPoligonal, const char* ficheroAproximacionPoligonal){

	fstream fichero;

	int line;

	assert ( aproximacionPoligonal.empty() );
	fichero.open(ficheroAproximacionPoligonal, ios::in);


	while(fichero>>line){
		aproximacionPoligonal.push_back( line );
	}

	assert( !aproximacionPoligonal.empty() );

	fichero.close();
}

/**
@fn T calcularError(const vector< Punto2D<T> > &contorno, const vector<int> &aproximacionPoligonal)
@brief Calcular la suma de errores en la aproximacion utilizando llamadas a funciones de la recta2D y calcularDistancia
@pre aproximacionPoligonal y contorno tengan elementos
@arg vector<int> &aproximacionPoligonal, vector de enteros para indice de puntos
@arg const vector< Punto2D<T> > &contorno, vector de puntos
@return T error
*/

double calcularError(const vector< Punto2D<double> > &contorno, const vector<int> &aproximacionPoligonal){

	assert (!contorno.empty());
	assert (!aproximacionPoligonal.empty());

	int i, j;
	int TAM = aproximacionPoligonal.size();
	int p1, p2;
	double error=0;


	for( i = 0 ; i < (TAM-1)  ; i++ ){
		if(i < (TAM-2)){
			p1 = aproximacionPoligonal[i];
			p2 = aproximacionPoligonal[i+1];

		}else{ //Cuando el punto i es el ultimo que tiene que hacer la recta con el primero
			p1 = aproximacionPoligonal[i];
			p2 = aproximacionPoligonal[0];

		}

		Punto2D <double> punto1 = contorno[p1];
		Punto2D <double> punto2 = contorno[p2];
		Recta2D <double> recta (punto1, punto2);
		Punto2D <double> intermedio (0.0, 0.0);



		if(i < (TAM-2)){
			for(j=p1+1 ; j<p2; j++){
				intermedio = contorno[j];
				error = error + pow(calcularDistancia(intermedio, recta), 2);
			}
		}else{ //Cuando el punto i es el ultimo que tiene que hacer la recta con el primero
			for(j=p1+1; j<contorno.size()-1; j++){
				intermedio = contorno[j];
				error = error + pow(calcularDistancia(intermedio, recta), 2);

			}

			for(j=0; j<p2; j++){
				intermedio = contorno[j];
				error = error + pow(calcularDistancia(intermedio, recta), 2);

			}
		}
	}

	return (error);
}

/**
@fn T calcularDistancia(const Punto2D<T> & p, const Recta2D<T> & recta)
@brief Calcular la distancia de un punto a la recta
@arg const Punto2D<T> & p
@arg const Recta2D<T> & recta
@return T distancia
*/


double calcularDistancia(const Punto2D<double> & p, const Recta2D<double> & recta){

	double distancia;

	distancia = recta.getA() * p.x() + recta.getB() * p.y() + recta.getC(); //a*x + b*y + c


	//Realiza el valor absoluto del numerador |a*x + b*y + c| / raiz(a^2 + b^2)
	if(distancia<0){
		distancia = distancia*(-1) / sqrt( pow( recta.getA(), 2 ) + pow( recta.getB(), 2 ) );
	}else{
		distancia = distancia / sqrt( pow( recta.getA(), 2 ) + pow( recta.getB(), 2 ) );
	}

	return (distancia);
}
