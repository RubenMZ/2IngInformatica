/**
@file algoritmos.hpp
@author Ruben
@brief Fichero con las cabeceras de los algoritmos
*/

#ifndef ALGORITMOS_H
#define ALGORITMOS_H

#include "graph_matrix.hpp"
#include "vertex.hpp"
#include "edge.hpp"
#include <vector>
#include <iostream>

using namespace std;
using namespace edi;


  /**
		@fn 	void profundidad( GraphMatrix g, const Vertex &v, vector<Vertex> &visitados);
		@brief	Realiza el recorrido en profundidad desde un nodo, mostrando por los nodos por los que va pasando
		@param 	g GraphMatrix
		@param 	v Vertex
		@param  visitados vector<Vertex>
  */

	void profundidad( GraphMatrix g, const Vertex &v, vector<Vertex> &visitados);

	 /**
		@fn 	bool estaVertex(vector<Vertex> vector, Vertex v);
		@brief 	Funcion que comprueba si un vertice esta en el vector de encontrados
		@param 	vector vector<Vertex>
		@param	v Vertex
		@return bool - true si lo ha encontrado y false en caso contrario
  */
	bool estaVertex(vector<Vertex> vector, Vertex v);

	/**
		@fn 	void algoritmoFloyd(GraphMatrix &g, float ** distancias, int ** intermedios);
		@brief	Funcion que aplica el algoritmo de floyd a un grafo y rellena las matrices de distancias e intermedios
		@param 	g GraphMatrix
		@param	distancias float **
		@param 	intermedios int **
  */
	void algoritmoFloyd(GraphMatrix &g, float ** distancias, int ** intermedios);

	/**
		@fn 	float caminoMin(GraphMatrix &g, float** distancias, int ** intermedios, const Vertex &origen, const Vertex &destino);
		@brief 	Funcion que gracias al algoritmo de Floyd puede darnos el camino minimo entre dos nodos
		@param	g GraphMatrix
		@param 	distancias float **
		@param 	intermedios int **
		@param 	origen Vertex
		@param 	destino Vertex
  */
	float caminoMin(GraphMatrix &g, float** distancias, int ** intermedios, const Vertex &origen, const Vertex &destino);

	/**
		@fn void mostrarMatrix(float ** matrix, const int &tam);
		@brief Funcion auxiliar para imprimir una matriz de float
		@param matrix float **
		@param tam int
	*/
	void mostrarMatrix(float ** matrix, const int &tam);

	/**
		@fn void copiaMatrix(float ** matrix, float ** copia, const int &tam);
		@brief Funcion auxiliar para copiar la matrix a la copia
		@param matrix float **
		@param copia float **
		@param tam int
	*/
	void copiaMatrix(float ** matrix, float ** copia, const int &tam);
#endif