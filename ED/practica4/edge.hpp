/**
@file edge.hpp
@brief Fichero con la clase Edge(lado)
@author Ruben
*/

#ifndef __EDGE_HPP__
#define __EDGE_HPP__


#include <cassert>
#include "vertex.hpp"


/*!
\brief Espacio de nombres para la asignatura Estructura de datos.

*/
namespace edi 
{
	/*!\brief Edge of graph.*/
	class Edge
	{
		private:
			double _data; //!<Weight of the edge
			Vertex _first; //!<First vertex of the edge
			Vertex _second; //!<Second vertex of the edge
			
		public:

			/**
				@fn		const double & getData()
				@brief 	Funcion que devuelve el atributo privado _data
				@return _data double
			*/
			const double & getData() const 
			{
				return _data;
			}

			/**
				@fn		const Vertex & first() const
				@brief 	Funcion que devuelve el atributo privado _first
				@return _first Vertex
			*/	
			const Vertex & first() const 
			{
				return _first;
			}
			/**
				@fn		const Vertex & second() const 
				@brief 	Funcion que devuelve el atributo privado _second
				@return _second Vertex
			*/	
			const Vertex & second() const 
			{
				return _second;
			}
			/**
				@fn 	bool has(const Vertex & u)
				@brief	Funcion que comprueba si un vertice pasado por parametro pertenece a este lado
				@param 	u Vertex
				@return	bool, que nos devolverá true si ese vertice pertenece a este lado y false en caso contrario
			*/
			bool has(const Vertex & u) const
			{
				return u == first() or u == second();
			}
			/**
				@fn 	const Vertex & other(const Vertex & u)
				@brief 	Funcion que nos devuelve el segundo vertice de este lado si le pasamos el primero
				@pre 	has(u) = true
				@param 	u Vertex
				@return	first o second
			*/
			//pre-c: has(u) = true
			const Vertex & other(const Vertex & u) const
			{
				assert(has(u));
				if (u == first())
					return second();
				return first();
			}
			//! @name Modificadores

			/*
				@fn 	void setData(const double & data)
				@brief 	Asigna al atributo privado _data el valor pasado por parametro
				@param 	data double
			*/
      void setData(const double & data) 
			{
				_data = data;				
			}

			/*
				@fn 	void setFirst(const Vertex & first)
				@brief 	Asigna al atributo privado _first el valor pasado por parametro
				@param 	first Vertex
			*/
			
      void setFirst(const Vertex & first) 
			{
				_first = first;
				
			}
			/*
				@fn 	void setSecond(const Vertex & second) 
				@brief 	Asigna al atributo privado _second el valor pasado por parametro
				@param 	second Vertex
			*/	
      void setSecond(const Vertex & second) 
			{
				_second = second;
			}
			/*! 
				@fn     bool operator==(const Edge &e)
				@brief  Sobrecarga del operador relacional de igualdad
				@param  e Edge
				@post   El valor devuelto debe ser true si el Lado actual es igual al lado e y false en caso contrario
				@return bool, valor lógico que indica si el Lado actual es igual que el Lado e
			*/
			bool operator==(const Edge &e)const
			{
				return (e.first() == first() and e.second() == second());
			}
	};

} //namespace ed

#endif
