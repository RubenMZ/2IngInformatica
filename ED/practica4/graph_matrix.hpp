/**
  @file   graph_matrix.hpp
  @brief  Definición de la clase GraphMatrix
  @author Ruben
*/

#ifndef __GRAPH_MATRIX_HPP__
#define __GRAPH_MATRIX_HPP__

#include <vector>
#include <iostream>
#include <cassert>

#include  "edge.hpp"
#include  "vertex.hpp"

using namespace std;


/**
@brief Espacio de nombres para la asignatura Estructura de datos.

*/
namespace edi 
{
	/*! @brief Class of GraphMatrix.*/
	class GraphMatrix
	{
		private:
			  
			//Capacity of graph (maximum value of _numVertexes. _capacity >= _numVertexes)
			unsigned int _numVertexes;//!<Num of the vertexes in the graph
			unsigned int _numEdges;//!<Num of the Edges in the graph
			unsigned int _capacity;//!<Capacity of the graph
			bool _directed;//!<Is directed
			Edge* _cursorE;//!<cursor of edges
			Vertex* _cursorV;//!<cursor of vertexes
			vector<Vertex> _vectorV;//!<Vector fo vertexes
			float** _matrixV;//!<Adjacency matrix of weights

		public:

			//* @name Constructores

			/** 
				@fn        GraphMatrix (const unsigned int & capacity=0, const bool & isDirected = true);
				@brief     Constructor por defecto de la clase GraphMatrix
				@param	   capacity unsigned int
				@param	   isDirected bool
			*/
			GraphMatrix (const unsigned int & capacity=0, const bool & isDirected = true);

			//*Observers
			/**
				@fn		const unsigned int &numVertexes()
				@brief	Observador del campo numVertexes
				@return _numVertexes unsigned int
			*/
			const unsigned int &numVertexes()const;
			/**
				@fn		const unsigned int &numEdges()
				@brief	Observador del campo numEdges
				@return _numEdges unsigned int
			*/
			const unsigned int &numEdges()const;
			
			/**
				@fn		const unsigned int &capacity()
				@brief	Observador del campo capacity
				@return _capacity unsigned int
			*/	
			const unsigned int &capacity()const;
			/**
				@fn		float ** getMatrix();
				@brief	Nos da la matriz de adyacencia
				@return _matrixV float**
			*/	
			float ** getMatrix();
			/**
				@fn		bool isEmpty()
				@brief	Nos dice si el grafo esta vacio
				@return bool, devuelve true si el grafo esta vacio y false en caso contrario
			*/	
			bool isEmpty() const; 
			/**
				@fn		const bool & isDirected()
				@brief	Nos dice si el grafo es dirigido
				@return Devuelve true si el grafo es dirigido y false en caso contrario
			*/	
			const bool & isDirected() const;
			
			/**
				@fn		const float adjacent(const Vertex & u, const Vertex & v)
				@brief	Devuelve el elemento de la matriz de adyacencia (INFINITO si no hay lado)
				@return retVal float
				@param u Edge 
				@param v Edge 
			*/	
			//Devuelve el elemento de la matriz de adyacencia (INFINITO si no hay lado)
			const float adjacent(const Vertex & u, const Vertex & v) const;
			
			/**
				@fn		bool hasCurrVertex()
				@brief	Está el cursor de vértices posición válida
				@return bool, devuelve true si existe el elemento al que apunta el vCursor
			*/	
			//Está el cursor de vértices posición válida
			bool hasCurrVertex() const; 
			
			/**
				@fn		const Vertex & currVertex()
				@pre 	hasCurrVertex() is true
				@brief	Devuelve el vértice referenciado por el cursor de vértices
				@return *_cursorV Vertex
			*/	
			//Pre: hasCurrVertex() is true.
			//Devuelve el vértice referenciado por cursor de vértices
			const Vertex & currVertex() const;
      
      		/**
				@fn		bool hasCurrEdge()
				@brief	Está el cursor de lados posición válida
				@return bool, devuelve true si el cursor está en posicion válida y false en otro caso
			*/
			//Está el cursor de lados posición válida
			bool hasCurrEdge() const;
			
			/**
				@fn		const Edge currEdge()
				@brief	Miramos si el lado referenciado por el cursor es valido
				@pre 	hasCurrEdge() is true
				@return *_cursorE Edge
			*/
			//Pre: hasCurrEdge() is true
			//Devuelve el lado referenciado por cursor de lados
			const Edge currEdge();
			
			//! @name Modificadores

			/**!
				@fn		void makeDirected()
				@brief	Crea un grafo dirigido
			*/
			
			//Crea un grafo dirigido
			void makeDirected();
			/**
				@fn		void makeUndirected()
				@brief	Crea un grafo no dirigido
			*/	
			//Crea un grafo no dirigido
			void makeUndirected();
			
			/**
				@fn		void addVertex(const std::string & data)
				@pre 	numVertexes() < capacity()
				@brief	Añade un vertice al grafo a partir del data
				@param 	data string
			*/
			//Prec: numVertexes() < capacity()
			//Añade un vertice al grafo a partir del data
			void addVertex(const std::string & data);
			
			/**
				@fn 	void addEdge(const double & data, const Vertex & u, const Vertex & v)
				@pre  	u y v pertenecen al grafo
				@brief	Añade un lado a partir de sus dos vértices y su peso. Esto se reflejará sólo en la matriz de adyacencia
				@param	data double
				@param	u Vertex
				@param 	v Vertex
			*/
			//Prec: u y v pertenecen al grafo
			//Añade un lado al grafo a partir de sus dos vértices y su peso. Esto se reflejará sólo en la matriz de adyacencia
			void addEdge(const double & data, const Vertex & u, const Vertex & v);
			
			/**
				@fn 	void searchVertex(const std::string &data)
				@brief  Busca un vertice a partir de su data, colocando el cursor en dicho vértice
				@param	data string
			*/		
			//Busca un vertice a partir de su data, colocando el cursor en dicho vértice
			bool searchVertex(const std::string &data);
      
      		/**
				@fn		void goTo(const Vertex & u)
				@pre 	u pertenece al grafo
				@brief 	Lleva el cursor a un vertice a partir de dicho vertice
				@param	u Vertex
			*/
			//Prec: u pertenece al grafo
			//Lleva el cursor a un vertice a partir de dicho vertice
			void goTo(const Vertex & u);
			
			/**
				@fn  	void goTo(const unsigned int &idx)
				@pre 	0 <= idx < numVertexes()
				@brief 	Lleva el cursor a un vértice a partir de la posicion de dicho vertice
				@param 	idx unsigned int
			*/
			//Prec: 0 <= idx < numVertexes()
			//lleva el cursor a un vértice a partir de la posicion de dicho vertice
			void goTo(const unsigned int &idx);

			/**
				@fn 	void searchEdge(const Vertex & u, const Vertex & v)
				@brief 	Lleva el cursor a un lado a partir de sus vertices
				@pre 	u y v pertenecen al grafo
				@param 	u Vertex
				@param	v Vertex
			*/
			//Prec: u y v pertenecen al grafo
			//Lleva el cursor a un lado a partir de sus vertices
			void searchEdge(const Vertex & u, const Vertex & v);

			/**
				@fn 	void beginVertex()
				@brief 	Lleva el cursor al primer vertice
			*/
			//Vertex cursor
			//Lleva el cursor al primer vertice
			void beginVertex();
			
			/**
				@fn		void nextVertex()
				@brief 	Avanza el cursor al siguiente vertice
			*/
			//Avanza el cursor al siguiente vertice
			void nextVertex();
			

			/**
				@fn 	bool afterEndVertex()
				@brief 	Comprueba si el cursor ha sobrepasado su última posicion válida en vertices
				@return	Devuelve true si lo ha sobrepasado, false en caso contrario
			*/
			bool afterEndVertex() const;

			/**
				@fn 	void beginEdge(const Vertex & u)
				@brief 	Lleva el cursor al primer lado que sale del vertice u
				@param 	u Vertex
			*/
			void beginEdge(const Vertex & u);
			/**
				@fn 	void nextEdge()
				@brief 	Avanza el cursor al siguiente lado que sale de currEdge().first()
			*/
			void nextEdge();
			
			/**
				@fn 	bool afterEndEdge()
				@brief	Comprueba si el cursor ha sobrepasado su última posicion válida para los lados que salen de currEdge().first()
				@return Devuelve true en caso de que sea cierto, false en caso contrario
			*/
			bool afterEndEdge();
	};
} //namespace ed

	#endif 
