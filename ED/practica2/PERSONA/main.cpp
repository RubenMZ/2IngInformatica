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
#include <iostream>
#include "generarpersona.hpp"
#include "asignatura.hpp"
#include <string>
#include <cstring>
#include <cstdio>



using namespace edi;
using namespace std;

int main(){

	int nAlumnos;
	string fichero="personas.txt";
	int menu=1;
	Persona p1, p2;
	string nombre, apellido;
	int dni;
	int opcion;

	cout<<"Creando lista de alumnos..."<<endl;
	cout<<"Introduce el numero de alumnos: ";
	cin>>nAlumnos;
	getchar();
	cout<<"Introduce el nombre del fichero: ";
	getline(cin, fichero);

	Asignatura edi(nAlumnos);
	edi.cargarLista( generarPersonas(fichero.c_str(), nAlumnos));

	while(menu!=0){
		cout<<"Lista de alumnos:"<<endl;
		cout<<"\t1) Mostrar lista orden ascendente."<<endl;
		cout<<"\t2) Mostrar lista orden descendente."<<endl;
		cout<<"\t3) Listar alumnos entre dos alumnos."<<endl;
		cout<<"\t4) Modificar alumno."<<endl;
		cout<<"\t0) SALIR"<<endl;
		cout<<"Opción: ";
		cin>>menu;

		switch(menu){

			case 1:		cout<<"Lista ascendente de alumnos:"<<endl;
						cout<<"============================"<<endl;
						edi.imprimirAscendente();
						break;

			case 2:		cout<<"Lista descendente de alumnos:"<<endl;
						cout<<"============================"<<endl;
						edi.imprimirDescendente();
						break;

			case 3:			cout<<"¿Que desea? Ascendente o descendente (1/2): ";
							cin>>opcion;

							getchar();
							cout<<"Introduce el nombre del primer alumno: ";
							getline(cin, nombre);
							cout<<"Introduce apellido: ";
							getline(cin, apellido);
							cout<<"Introduce DNI: ";
							cin>>dni;
							p1.nombre(nombre.c_str());
							p1.apellido(apellido.c_str());
							p1.dni(dni);

							getchar();
							cout<<"Introduce el nombre del segundo alumno: ";
							getline(cin, nombre);
							cout<<"Introduce apellido: ";
							getline(cin, apellido);
							cout<<"Introduce DNI: ";
							cin>>dni;
							p2.nombre(nombre.c_str());
							p2.apellido(apellido.c_str());
							p2.dni(dni);

							if(opcion==2){
								edi.listarEntreDosDescendente(p1,p2);
							}else{
								edi.listarEntreDosAscendente(p1,p2);
							}



						break;

			case 4:			getchar();
							cout<<"Introduce el nombre del alumno a modificar: ";
							getline(cin, nombre);
							cout<<"Introduce apellido: ";
							getline(cin, apellido);
							cout<<"Introduce DNI: ";
							cin>>dni;
							p1.nombre(nombre.c_str());
							p1.apellido(apellido.c_str());
							p1.dni(dni);

							getchar();
							cout<<"Introduce el nuevo nombre: ";
							getline(cin, nombre);
							cout<<"Introduce el nuevo apellido: ";
							getline(cin, apellido);
							cout<<"Introduce el nuevo dni: ";
							cin>>dni;
							p2.nombre(nombre.c_str());
							p2.apellido(apellido.c_str());
							p2.dni(dni);


							edi.modificarAlumno(p1,p2);
						break;

			case 0:     getchar();
						cout<<"Pulse cualquier tecla para cerrar..."<<endl;
						getchar();
						break;

			default:	cout<<"Opcion incorrecta"<<endl;
						break;
		}
	}


	



	return 0;
}
