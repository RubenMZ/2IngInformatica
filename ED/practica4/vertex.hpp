/*!
  @file   vertex.hpp
  @brief  Definición de la clase Vertex
  @author Ruben
*/

#ifndef __VERTEX_HPP__
#define __VERTEX_HPP__

#include <iostream>
#include <cassert>


/*!
@brief Espacio de nombres para la asignatura Estructura de datos.

*/
namespace edi 
{

	/*! @brief Vertex of Graph.*/
	class Vertex
	{
		private:
			std::string _data; //!< Data of the vertex
			int _label; //!< Label of the vertex
		
		public:
			//! @name Observadores

			/**
				@fn 	const std::string & getData()
				@brief 	Funcion que devuelve el atributo data
				@return _data string
			*/
			const std::string & getData()const
			{ 
				return _data;
			}
			
			/**
				@fn 	const int & getLabel()
				@brief 	Funcion que devuelve el atributo label
				@return _label int
			*/
			const int & getLabel()const
			{
				return _label;
			}
			
			//! @name Modificadores

			/**
				@fn 	void setData(const std::string &data)
				@brief 	Asigna al atributo _data el valor pasado por parametro
				@param 	data string
			*/
			void setData(const std::string &data)
			{
				_data = data;
			}
			
			/**
				@fn 	void setLabel(const int &label)
				@brief 	Asigna al atributo _label el valor pasado por parametro
				@param 	label int
			*/
			void setLabel(const int &label)
			{
				_label = label;
			}
			
			//! @name Operadores

			/**
				@fn 	bool operator==(const Vertex &v)
				@brief 	Sobrecarga del operador relacional de igualdad
				@param 	v Vertex
				@return Valor logico que indica si el vertice actual es igual que el vertice v
			*/
			bool operator==(const Vertex &v)const
			{
				return (v.getData() == getData());
			}

			/**
				@fn 	bool operator!=(const Vertex &v)
				@brief 	Sobrecarga del operador relacional de distinción	
				@param 	v Vertex
				@return	Valor logico que indica si el vertice actual es distinto al vertice v
			*/
			
			bool operator!=(const Vertex &v)const
			{
				return (v.getData() != getData());
			}
	};
	
	
} //namespace ed

#endif 
