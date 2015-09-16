#ifndef RECTA2D_H
#define RECTA2D_H

#include "Punto2D.h"
#include <cassert>


 /**
@file Recta2D.h
@brief Fichero de la clase Recta2D con sus respectivas funciones : observadores, modificadores y metodos
@author Ruben Medina
@date 23-02-15
@version 1.0
 */


template <class T>
/**
@class Recta2D
@brief Clase que representa una recta en dos dimensiones ax+by+c=0
*/
class Recta2D{
	private:
		T a_, b_, c_;

	public:

		/**
		@fn Recta2D(T const& a, T const& b, T const& c)
		@arg T const& a
		@arg T const& b
		@arg T const& c
		@brief Constructor inline de la clase
		*/
		Recta2D(T const& a, T const& b, T const& c){
			a_=a;
			b_=b;
			c_=c;
		}

		/**
		@fn Recta2D( Punto2D<T> &  p1,  Punto2D<T> &  p2)
		@arg Punto2D<T> &  p1
		@arg Punto2D<T> &  p2
		@pre p1 y p2 sean distintos
		@brief Constructor inline de la clase a partir de dos puntos
		*/

		Recta2D( Punto2D<T> &  p1,  Punto2D<T> &  p2){
			
			assert( !p1.sonIguales(p2) );
			a_ = p2.y() - p1.y();//y2 - y1
			b_ = p1.x() - p2.x();//x1 - x2
			c_ = p1.y() * ( p2.x()-p1.x() ) - p1.x() * ( p2.y() - p1.y() );//y1*(x2-x1) - x1*(y2-y1)
		
		}

		/**
		@fn inline T getA()const{ return(a_); };
		@brief Observador inline de a
		@return T a
		*/
		inline T getA()const{ return(a_); };

		/**
		@fn inline T getB()const{ return(b_); };
		@brief Observador inline de b
		@return T b
		*/
		inline T getB()const{ return(b_); };
		
		/**
		@fn inline T getC()const{ return(c_); };
		@brief Observador inline de c
		@return T c
		*/
		inline T getC()const{ return(c_); };

		/**
		@fn inline void setA( T const& valor){ a_ = valor; };
		@brief Modificador inline de a
		@arg T const& valor
		*/
		inline void setA( T const& valor){ a_ = valor; };

		/**
		@fn inline void setB( T const& valor){ b_ = valor; };
		@brief Modificador inline de b
		@arg T const& valor
		*/
		inline void setB( T const& valor){ b_ = valor; };

		/**
		@fn inline void setC( T const& valor){ c_ = valor; };
		@brief Modificador inline de c
		@arg T const& valor
		*/
		inline void setC( T const& valor){ c_ = valor; };

};

#endif
