/**
@file main.cpp
@author Rubén
@brief Programa principal que utiliza grafos para aplicar algoritmos de Floyd y Camino Minimo
@date 18/05/2015
*/

#include <iostream>
#include <fstream>
#include  "edge.hpp"
#include  "vertex.hpp"
#include "graph_matrix.hpp"
#include "entrada_salida.hpp"
#include "algoritmos.hpp"
#include "cstdlib"

int main ()
{
	//Declaramos las distintas variables

	edi::GraphMatrix *g = 0;//Puntero a un grafo
	bool cargado = false;//Comprueba si el fichero del grafo se ha cargado
	std::string nombreFicheroGrafo;//Nombre del fichero del grafo
	float ** distancias;//Matriz de distancias
	int ** intermedios;//Matriz de intermedios
	Vertex origen, destino;//Vertice origen y destino para la distancia
	string localidad1, localidad2;//Cadena para las localidades
	float distan;//Distancia entre la localidad1 y localidad2
	vector<Vertex> explorados;//Vector de explorados para el algoritmo de profundidad
	int opcionMenu=0;//Opcion del menu principal
	bool existeLoc1=false, existeLoc2=false;//Variables para comprobar si existen las localidades.

	while(opcionMenu!=5){
		cout<<"_________________________________________"<<endl;
		cout<<"|Elige una de las siguientes opciones:   |"<<endl;
		cout<<"|	1. Cargar grafo.                 |"<<endl;
		cout<<"|	2. Mostrar grafo.                |"<<endl;
		cout<<"|	3. Recorrido en profundidad.     |"<<endl;
		cout<<"|	4. Distancia entre dos nodo.     |"<<endl;
		cout<<"|	5. Salir.                        |"<<endl;
		cout<<"|________________________________________|"<<endl;
		cout<<"Opcion:";
		cin>>opcionMenu;


		switch(opcionMenu){

		case 1: //Carga el grafo desde el fichero con nombreFicheroGrafo
				cout << "Nombre del fichero grafo: ";
  				cin >> nombreFicheroGrafo;
				cargado = cargarGrafo(g, nombreFicheroGrafo);
				//Si esta cargado correctamente entonces...

				if(cargado){
					//Reserva memoria para la matriz de distancias e intermedios
					distancias=(float **)malloc(sizeof(float*)*(g->capacity()));
					
					for(unsigned int i=0; i<g->capacity(); i++){
						distancias[i]=(float *)malloc(sizeof(float)*(g->capacity()));
					}

					intermedios=(int **)malloc(sizeof(int*)*(g->capacity()));
					
					for(unsigned int i=0; i<g->capacity(); i++){
						intermedios[i]=(int *)malloc(sizeof(int)*(g->capacity()));
					}
					//Copia la matriz del grafo a la matriz de distancias
					copiaMatrix(g->getMatrix(), distancias, g->capacity());
					//Inicializa la matriz de intermedios a 0
					for (unsigned int i = 0; i < g->capacity(); ++i)
					{
						for (unsigned int j = 0; j < g->capacity(); ++j)
						{
							intermedios[i][j]=0;
						}
					}
				}else
					cout << "El grafo no se ha podido cargar\n";

				break;
		case 2: //Muestra los datos del grafo si se ha cargado correctamente
				if(cargado){
					//Muestra info sobre los vertices y los lados
					mostrarGrafo(*g);
					//Muestra la matriz de distancias
					cout<<"Distancias"<<endl;
					cout<<"==========="<<endl;
					mostrarMatrix(g->getMatrix(), g->capacity());
				}else
					cout << "El grafo no se ha podido cargar\n";

				break;
		case 3:	//Realiza el recorrido en profundidad a partir de un nodo
				if(cargado){
				explorados.clear();
				cout<<"Introduce el nodo origen: ";
				cin>>localidad1;
				//Si existe el nodo con esa localidad lo mete en origen
				if( (existeLoc1=g->searchVertex(localidad1)) ==true )
					origen=g->currVertex();
				else
					cout<<"No existe ese nodo"<<endl;
				//Ejecuta el algoritmo si existe ese nodo origen
				if(existeLoc1)
					profundidad(*g, origen, explorados);

				}else{
					cout << "El grafo no se ha podido cargar\n";
				}
				break;

		case 4:	//Realiza el algoritmo de floyd y el caminoMinimo
				//para calcular el recorrido
				//mas corto entre dos nodos

				if(cargado){
					//Ejecuta el algoritmo de floyd para calcular las distancias 
					//minimas de todos los nodos entre si
					algoritmoFloyd(*g, distancias, intermedios);		
					
					//Pide las localidades a buscar comprobando si existen esos nodos
					cout<<"Introduce la primera localidad: ";
					cin>>localidad1;
					if( (existeLoc1=g->searchVertex(localidad1))==true )
						origen=g->currVertex();
					else
						cout<<"No existe ese nodo"<<endl;
		
					cout<<"Introduce la segundo localidad: ";
					cin>>localidad2;
					if( (existeLoc2=g->searchVertex(localidad2)) ==true)
						destino=g->currVertex();
					else
						cout<<"No existe ese nodo"<<endl;

					//Si existen esos nodos y todo va correcto, imprime el 
					//recorrido entre las dos localidades y devuelve la distancia entre ellas
					if(existeLoc1 && existeLoc2){
						distan=caminoMin(*g, distancias, intermedios, origen, destino);
						cout<<destino.getData()<<endl;
		  
		  				cout<<endl<<"La localidad "<<localidad1<<" dista "<<distan<<" de la localidad "<<localidad2<<endl;
  					}
  				}else{
  					cout << "El grafo no se ha podido cargar\n";
  				}
				break;

		case 5:	//Cierra el programa
				cout<<"Pulsar ENTER para terminar...";
				getchar();
				getchar();
				break;

		default: 
				cout<<"La opcion "<<opcionMenu<<" no es correcta"<<endl;
				break;

		}

	}

  return 0;
}