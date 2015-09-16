/**
@file gestorFichero.cpp
@brief Gestor de copias de seguridad para las personas
*/

#include "gestorFichero.hpp"
#include <fstream>
#include <cstddef>

using namespace std;

	/**
	@file void guardarLista(const LinkedList<Persona> &lista, const char * fichero)
	@brief Guarda la lista del parametro en un fichero con el nombre del segundo argumento
	@arg const LinkedList<Persona> &lista
	@arg const char * fichero
	*/

	void guardarLista(const LinkedList<Persona> &lista, const char * fichero){
		ofstream f;
		f.open(fichero);
		Persona alumno;
		LinkedList<Persona> auxlist = lista;

		if(f.is_open()){
			for(int i=0; auxlist.isValid(i); ++i){
				if(auxlist.isValid(i)){			
					alumno=auxlist.item(i);
					f<<alumno;
				}
			}
		}

		f.close();
	}

	/**
	@file void cargarLista(LinkedList<Persona> &lista, const char * fichero)
	@brief Carga la lista del parametro desde un fichero con el nombre del segundo argumento
	@arg LinkedList<Persona> &lista
	@arg const char * fichero
	@return Numero actualizado de elementos
	*/

	int cargarLista(LinkedList<Persona> &lista, const char * fichero){
		ifstream f;
		f.open(fichero);
		Persona alumno;
		LinkedList<Persona> auxlist;
		int nEle=0;

		if(f.is_open()){
			while(!f.eof()){			
					f>>alumno;
					if(alumno.nombre()!=""){
						auxlist.insert(alumno);
						nEle++;						
					}

			}
		}

		lista=auxlist;
		f.close();

		return (nEle);
	}
