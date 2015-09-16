/**
@file algoritmos.cpp
@author Ruben
@brief Archivo con las declaraciones de las funciones para los algorimos de profundidad, camino minimo y algoritmo de Floyd
*/
#include "algoritmos.hpp"
#include <limits>

	using namespace edi;

	void profundidad(GraphMatrix g, const Vertex &v, vector<Vertex> &visitados){
		//Con el puntero apunta al primer vertice del nodo v
		g.beginEdge(v);
		//Mete el vertice en el vector de visitados
		visitados.push_back(v);
		//Lo imprime
		cout<<v.getLabel()<<" ) "<<v.getData()<<endl;
			//Si es el ultimo vertice, el tamaño del vector sera la capacidad y termina
			if(visitados.size()>=g.capacity()){
				cout<<"Fin del grafo"<<endl;
			}else{
				//Sino, se mete en el bucle para recorrer los lados del nodo
				while(!g.afterEndEdge() && visitados.size()<=g.capacity()){
					//Si por cada lado, el nodo segundo no esta en visitados
					if(!estaVertex(visitados, g.currEdge().second())){
						//Vuelve a llamar a la funcion para evaluar ese nodo y sus lados
						profundidad(g, g.currEdge().second(), visitados);
					}
					//Una vez evaluado el nodo y llegado a nodos visitados o nodos hojas
					//Se incrementa el lado
					g.nextEdge();
				}
			}

	}

	bool estaVertex(vector<Vertex> vector, Vertex v){
		bool retVal=false;
		//Recorre el vector en busca del vertice v 
		for (unsigned int i = 0; i < vector.size() && retVal==false; ++i)
		{
			if(vector[i].getData()==v.getData())
				retVal=true;
		}
		//Si ya esta insertado devuelve true	
		return retVal;
	}

	void algoritmoFloyd(GraphMatrix &g, float ** distancias, int ** intermedios){

		float suma;
		int n=g.capacity();
		//Inicializa la diagonal de la matriz distancias a 0		
    for(int i = 0; i < n; i++)
        distancias[i][i] = 0;
 	
 	//Hace un triple bucle para recorrer la matriz de distancias
 	//a la vez que se recorre la fila y columna por cada elemento
    for(int k = 0; k < n; k++)
    	//Para cada elemento k se recorre la matriz para comprobar si
    	//utilizando k como intermedio se recorta la distancia
        for(int i = 0; i < n; i++)
            for(int j = 0; j < n; j++){
                //Si alguna distancia al elemento k desde i a k o de k a j
                //fuera infinito, la suma es infinito
            	if(distancias[i][k]==std::numeric_limits<float>::infinity() || distancias[k][j]==std::numeric_limits<float>::infinity()){ 
					suma=std::numeric_limits<float>::infinity();
				}else{ 
					suma = distancias[i][k] + distancias[k][j];
				}
				//Si la distancia de i a j con k de intermedio es menor que la distancia
				//anterior entonces se coloca la nueva distancia y k como intermedio
                if(distancias[i][j] > suma){
                    distancias[i][j] = suma;
                    intermedios[i][j]= k;
            	}
            }
 
	}

	
	float caminoMin(GraphMatrix &g, float** distancias, int ** intermedios, const Vertex &origen, const Vertex &destino){

			float suma=0;
			Vertex aux;
			unsigned int label;

			//Si el valor intermedio entre origen y destino es 0
			//quiere decir que la distancia minima es directa	
			if(intermedios[origen.getLabel()][destino.getLabel()]==0){
				cout<<origen.getData()<<" -> ";
				return (distancias[origen.getLabel()][destino.getLabel()]);
			}else{
				//Sino se trata con la etiqueta del valor intermedio
				label=intermedios[origen.getLabel()][destino.getLabel()];
				//Se apunta al vertice con esa etiqueta
				g.goTo( label );
				//Y si recoge el vertice
				aux=g.currVertex();
				//Una vez aqui evaluamos de forma recursiva la distancia
				//del origen a ese vertice y de ese vertice al destino
				suma+= caminoMin(g, distancias, intermedios, origen, aux);
				suma+= caminoMin(g, distancias, intermedios, aux, destino);

				return (suma);
			}
	}


void mostrarMatrix(float ** matrix, const int &tam){	
		for (int i = 0; i < tam; ++i)
		{
			cout<<"| ";
			for ( int j = 0; j < tam;++j)
			{
				cout<<" "<<matrix[i][j]<<" ";
			}
			cout<<" |"<<endl;
		}
	}

	void copiaMatrix(float ** matrix, float ** copia, const int &tam){
		for (int i = 0; i < tam; ++i)
		{
			for (int j = 0; j < tam; ++j)
			{
				copia[i][j]=matrix[i][j];
			}
		}

	}