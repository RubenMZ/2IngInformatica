#ifndef FUNCIONES_H
#define FUNCIONES_H
 /**
@file funciones.h
@brief Fichero de cabecera para las funciones.cpp
@author Ruben Medina
@date 23-02-15
@version 1.0
 */

#include "Punto2D.h"
#include "Recta2D.h"
#include <vector>





using namespace std;


void cargarContorno(vector< Punto2D<double> > & contorno, const char * ficheroContorno );

void cargarAproximacionPoligonal(vector<int> &aproximacionPoligonal, const char* ficheroAproximacionPoligonal);


double calcularError(const vector< Punto2D<double> > &contorno, const vector<int> &aproximacionPoligonal);


double calcularDistancia(const Punto2D<double> & p, const Recta2D<double> & recta);

#endif
