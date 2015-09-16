/**
@file gestorFichero.hpp
@brief Cabeceras para el gestor de copias de seguridad para las personas
*/
#ifndef GESTORFICHERO_H
#define GESTORFICHERO_H
#include "edi_LinkedList.hpp"
#include "persona.hpp"

using namespace edi;

	/**
	@file void guardarLista(const LinkedList<Persona> &lista, const char * fichero)
	@brief Guarda la lista del parametro en un fichero con el nombre del segundo argumento
	@arg const LinkedList<Persona> &lista
	@arg const char * fichero
	*/
	void guardarLista(const LinkedList<Persona> &lista, const char * fichero);

	/**
	@file void cargarLista(LinkedList<Persona> &lista, const char * fichero)
	@brief Carga la lista del parametro desde un fichero con el nombre del segundo argumento
	@arg LinkedList<Persona> &lista
	@arg const char * fichero
	@return Numero actualizado de elementos
	*/
	int cargarLista(LinkedList<Persona> &lista, const char * fichero);


#endif
