/**
@file funcionesArbol.cpp
@brief Definicion de las funciones auxiliares a la clase arbol
@author Ruben
*/

#include "funcionesArbol.hpp"

	/**
	 	@fn void creaArbol(LinkedList<Persona>& lista, LinkedOrderedBinaryTree<Clave> & tree);
	 	@brief Pasa la lista de personas del parametro a un arbol de claves (dni)
	 	@param LinkedList <Persona> lista
	 	@param LinkedOrderedBinaryTree<Clave> & tree
	 	@return void
	*/
	void creaArbol(LinkedList<Persona>& lista, LinkedOrderedBinaryTree<Clave> & tree){
		int i=0;
		Persona auxP;
		Clave auxC;

		while(lista.isValid(i)){

			auxP = lista.item(i);
			
			auxC.setDni(auxP.dni());
			auxC.setPosicion(i);

			tree.insert(auxC);

			i++;
		}
	}

