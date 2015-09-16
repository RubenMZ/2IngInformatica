/**
@file funcionesArbol.hpp
@brief Cabeceras para las funciones auxiliares del arbol
@author Ruben
*/

#ifndef FUNCIONESARBOL_H
#define FUNCIONESARBOL_H

#include "edi_LinkedList.hpp"
#include "edi_LinkedOrderedBinaryTree.hpp"
#include "persona.hpp"
#include "clave.hpp"


using namespace edi;

	/**
	 	@fn void creaArbol(LinkedList<Persona>& lista, LinkedOrderedBinaryTree<Clave> & tree);
	 	@brief Pasa la lista de personas del parametro a un arbol de claves (dni)
	 	@param LinkedList <Persona> lista
	 	@param LinkedOrderedBinaryTree<Clave> & tree
	 	@return void
	*/
	void creaArbol(LinkedList<Persona>& lista, LinkedOrderedBinaryTree<Clave> & tree);

#endif