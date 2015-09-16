/**
@file asignatura.hpp
@author Ruben
*/
#ifndef ASIGNATURA_H
#define ASIGNATURA_H

#include "edi_LinkedList.hpp"
#include "persona.hpp"
#include <vector>
#include <cstdlib>
#include <cstddef>
#include <iostream>

using namespace std;
using 

namespace edi;

/**
@class Asignatura
@brief Class that represents a subject with students making a list.

*/

class Asignatura{
	
	private:
			LinkedList<Persona> alumnos_;
			int numeroAlumnos_;
	public:
			/**
				@fn Asignatura(int num)
				@brief Constructor initializes numeroAlumnos if num is between 0-100
				@arg[in] int num
			*/
			Asignatura(){

			}

			Asignatura(int num){
				if(num<=100)
				numeroAlumnos_=num;
				else
				 exit(-1);
			}

			LinkedList<Persona> getLista()const{
				return (alumnos_);
			}
			void setLista(const LinkedList<Persona> &l){
				alumnos_=l;
			}

			int getNumeroAlumnos()const{
				return(numeroAlumnos_);
			}

			void setNumeroAlumnos(const int & num){
				if(num<=100)
				numeroAlumnos_=num;
				else
				exit(-1);
			}
			/**
				@fn void cargarLista(vector <Persona> v)
				@brief It loads the list from a vector of class Persona
				@arg[in] vector<Persona> v
			*/
			void cargarLista(vector <Persona> v){
				while(!v.empty()){
					alumnos_.insert(v.back());
					v.pop_back();
				}
			}
			/**
				@fn void imprimirAscendente()
				@brief It prints the list in ascending order
			*/
			void imprimirAscendente(){
				Persona alumno;

				for(int i=0;(i<numeroAlumnos_); i++){
					alumno=alumnos_.item(i);
					cout<<alumno;
				}
			}
			/**
				@fn void imprimirDescendente()
				@brief It prints the list in descending order
			*/
			void imprimirDescendente(){
				Persona alumno;

				for(int i=(numeroAlumnos_-1);i>=0; i--){
					alumno=alumnos_.item(i);
					cout<<alumno;
				}
			}
			/**
				@fn void listarEntreDosAscendente( Persona p1,  Persona p2)
				@brief It prints the list in ascending order between two students
				@arg[in] Persona p1
				@arg[in] Persona p2
			*/
			void listarEntreDosAscendente( Persona p1,  Persona p2){
				Persona aux;

				if(p1>p2){
					aux=p1;
					p1=p2;
					p2=aux;
				}
				if(p1==p2){
					cout<<p1;
				}else{
				for(int i=0;(i<numeroAlumnos_); i++){
					aux=alumnos_.item(i);
					if(aux>=p1 && aux<=p2){
						cout<<aux;
					}
				}
				}
			}
			/**
				@fn void listarEntreDosDescendente( Persona p1, Persona p2)
				@brief It prints the list in descending order between two students
				@arg[in] Persona p1
				@arg[in] Persona p2
			*/
			void listarEntreDosDescendente( Persona p1, Persona p2){
				Persona aux;

				if(p1>p2){
					aux=p1;
					p1=p2;
					p2=aux;
				}

				if(p1==p2){
					cout<<p1;
				}else{
				for(int i=(numeroAlumnos_-1);i>=0; i--){
					aux=alumnos_.item(i);
					if(aux>=p1 && aux<=p2){
						cout<<aux;
					}
				}
				}
			}
			/**
				@fn void modificarAlumno(Persona oldP, Persona newP)
				@brief It modifies an element, deleting the previous and inserting the current
				@arg[in] Persona oldP
				@arg[in] Persona newP
			*/
			void modificarAlumno(Persona oldP, Persona newP){
				int posicion=alumnos_.findItem(oldP);
				alumnos_.deletePosition(posicion);
				alumnos_.insert(newP);
			}
};

#endif
