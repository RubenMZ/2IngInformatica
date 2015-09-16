/**
@file main.cpp
@author Ruben
@date 07/04/2015
@brief Main which executes functions about a subject as list.
*/

#include "edi_LinkedNode.hpp"
#include "edi_List.hpp"
#include "edi_LinkedList.hpp"
#include "edi_exports.hpp"
#include "gestorFichero.hpp"
#include "generarpersona.hpp"
#include "asignatura.hpp"
#include "clave.hpp"
#include "funcionesArbol.hpp"
#include "edi_LinkedOrderedBinaryTree.hpp"

#include <string>
#include <cstring>
#include <cstdio>
#include <iostream>


using namespace edi;
using namespace std;

int main(){

	int nAlumnos;
	string fichero="personas.txt";
	string ficheroCopia;
	string ficheroArbol;
	int menu=1;
	string nombre, apellido;
	int dni;
	int opcion;

	LinkedList<Persona> auxlist;
	LinkedOrderedBinaryTree<Clave> arbol;
	Clave auxClave;
	Persona p1;
	bool borraArbol;
	char borrar;

	Asignatura edi;
	

	while(menu!=0){
		cout<<"Lista de alumnos:"<<endl;
		cout<<"\t1) Crear asignatura y arbol de claves"<<endl;
		cout<<"\t2) Guardar asignatura"<<endl;
		cout<<"\t3) Cargar asignatura"<<endl;
		cout<<"\t4) Busca a una persona en la asignatura."<<endl;
		cout<<"\t5) Mostrar asignatura"<<endl;
		cout<<"\t0) SALIR"<<endl;
		cout<<"Opción: ";
		cin>>menu;

		switch(menu){

			case 1:	cout<<"Creando lista de alumnos..."<<endl;
					cout<<"Introduce el numero de alumnos: ";
					cin>>nAlumnos;
					edi.setNumeroAlumnos(nAlumnos);
					getchar();
					cout<<"Introduce el nombre del fichero para leer las personas: ";
					getline(cin, fichero);
					edi.cargarLista( generarPersonas(fichero.c_str(), nAlumnos));
					auxlist=edi.getLista();
					creaArbol(auxlist, arbol);
					break;

			case 2:	getchar();
					cout<<"Introduce el nombre del fichero (sin extension): ";
					getline(cin, ficheroCopia);
					guardarLista(edi.getLista(), (ficheroCopia+".txt").c_str());
					arbol.guardaFichero(&arbol, (ficheroCopia+".idx").c_str());
					break;

			case 3:	getchar();
					if(!arbol.isEmpty()){
						cout<<"Ya esta cargado, ¿desea borrar? (s/n): " ;
						cin>>borrar;
						getchar();
						if(borrar=='s'){
							LinkedOrderedBinaryTree<Clave> aux;
							arbol=aux;
							cout<<"Introduce nombre fichero para cargar (sin extension): ";   
							getline(cin, ficheroCopia);
							auxlist=edi.getLista();
							edi.setNumeroAlumnos( cargarLista(auxlist, (ficheroCopia+".txt").c_str()) );
							edi.setLista(auxlist);
							arbol.cargaFichero(&arbol, (ficheroCopia+".idx").c_str());
						}
					}else{
							cout<<"Introduce nombre fichero para cargar (sin extension): ";   
							getline(cin, ficheroCopia);
							auxlist=edi.getLista();
							edi.setNumeroAlumnos( cargarLista(auxlist, (ficheroCopia+".txt").c_str()) );
							edi.setLista(auxlist);
							arbol.cargaFichero(&arbol, (ficheroCopia+".idx").c_str());
					}
						
					break;

			case 4:		cout<<"Introduce dni: ";
						getchar();
						cin>>dni;
						auxClave.setDni(dni);
						if(arbol.search(auxClave)){
							auxClave=arbol.buscaPosicion(auxClave);
							auxlist=edi.getLista();
							p1=auxlist.item(auxClave.getPosicion());
							cout<<p1;
						}else{
							cout<<"No se encuentra"<<endl;
						}
						

						break;

			case 5:	
					cout<<"Lista ascendente de alumnos:"<<endl;
					cout<<"============================"<<endl;
					edi.imprimirAscendente();
					break;

			case 0: cout<<"Pulsa enter para continuar...";
					getchar();
					getchar();
						break;
			default:	cout<<"Opcion incorrecta"<<endl;
						break;
		}
	}


	



	return 0;
}
