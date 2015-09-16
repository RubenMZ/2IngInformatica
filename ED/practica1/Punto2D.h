#ifndef PUNTO2D_H
#define PUNTO2D_H

 /**
@file Punto2D.h
@brief Fichero de la clase Punto2D con sus respectivas funciones : observadores, modificadores y metodos
@author Ruben Medina
@date 23-02-15
@version 1.0
 */


#include <cassert>



template<class T>
/**
@class Punto2D
@brief Clase que representa los puntos en dos dimensiones x/y
*/
class Punto2D{

	private:
		T x_, y_;

	public:

		/**
		@fn inline Punto2D(T const& x, T const& y)
		@arg T const& x
		@arg T const& y
		@brief Constructor inline de la clase
		*/
		inline Punto2D(T const& x, T const& y){
			x_ = x;
			y_ = y;
		};

		/**
		@fn inline T x()const{return(x_);};
		@return T x_;
		@brief Observador inline del campo x
		*/
		inline T x()const{return(x_);};
				/**
		@fn inline T y()const{return(y_);};
		@return T y_;
		@brief Observador inline del campo y
		*/
		inline T y()const{return(y_);};

		/**
		@fn bool sonIguales(Punto2D p)
		@brief Compara dos puntos para ver si son iguales
		@arg Punto2D p 
		@post Ambas variables x/y tienen que ser iguales al p.x/p.y
		@return boolean
		*/

		bool sonIguales(const Punto2D &p)const{
			bool ret = ( x()==p.x() )&& ( y()==p.y() );
			#ifndef NDEBUG
			if(ret)			
				assert( ( x()==p.x() )&& ( y()==p.y() ) );
			#endif
			return(ret);
		}

};

#endif
