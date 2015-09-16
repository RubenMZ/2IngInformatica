/*!
  @file   graph_matrix.cpp
  @brief  Definición de las funciones de la clase GraphMatrix
  @author Ruben
*/

#include "graph_matrix.hpp"
#include <limits>
#include <cstdlib>
#include <cstring>


using namespace edi;

			GraphMatrix::GraphMatrix (const unsigned int & capacity, const bool & isDirected){
				_capacity=capacity;
				_matrixV=(float **)malloc(sizeof(float*)*capacity);
				
				for(unsigned int i=0; i<capacity; i++){
					_matrixV[i]=(float *)malloc(sizeof(float)*capacity);
				}
				for (unsigned int i = 0; i < capacity; ++i)
				{
					for (unsigned int j = 0; j < capacity; ++j)
					{
						if(i==j){
							_matrixV[i][j]=0;
						}else{
							_matrixV[i][j]=std::numeric_limits<float>::infinity();
						}
					}
				}


				_directed=isDirected;
				_cursorV=NULL;
				_cursorE=NULL;
				_numVertexes=0;
				_numEdges=0;
			}


			//Observers
			const unsigned int &GraphMatrix::numVertexes()const{
				return(_numVertexes);
			}
			
			const unsigned int &GraphMatrix::numEdges()const{
				return(_numEdges);
			}
			
			const unsigned int &GraphMatrix::capacity()const{
				return(_capacity);
			}

			float ** GraphMatrix::getMatrix(){
				return(_matrixV);
			}
			
			bool GraphMatrix::isEmpty() const{
				return(_numVertexes==0);
			}
			
			const bool & GraphMatrix::isDirected() const{
				return(_directed);
			}
			
			//Devuelve el elemento de la matriz de adyacencia (INFINITO si no hay lado)
			const float GraphMatrix::adjacent(const Vertex & u, const Vertex & v) const{

				float* retVal=NULL;
				retVal=&_matrixV[u.getLabel()][v.getLabel()];

				if(retVal==NULL){
					return ( std::numeric_limits<float>::infinity() );
				}
				return (*retVal);
			}
			
			//Está el cursor de vértices posición válida
			bool GraphMatrix::hasCurrVertex() const{
				return(_cursorV!=NULL);
			} 
			
			//Pre: hasCurrVertex() is true.
			//Devuelve el vértice referenciado por cursor de vértices
			const Vertex & GraphMatrix::currVertex() const{
				return(*_cursorV);
			}
      
			//Está el cursor de lados posición válida
			bool GraphMatrix::hasCurrEdge() const{
				return(_cursorE!=NULL);
			}
			
			//Pre: hasCurrEdge() is true
			//Devuelve el lado referenciado por cursor de lados
			const Edge GraphMatrix::currEdge(){
				return(*_cursorE);
			}
			
			//Modifiers
			
			//Crea un grafo dirigido
			void GraphMatrix::makeDirected(){
				_directed=true;
			}
			
			//Crea un grafo no dirigido
			void GraphMatrix::makeUndirected(){
				_directed=false;
			}

			//Prec: numVertexes() < capacity()
			//Añade un vertice al grafo a partir del data
			void GraphMatrix::addVertex(const std::string & data){
				assert(numVertexes()<capacity());
				Vertex v;
				v.setData(data);
				v.setLabel(_numVertexes);
				_vectorV.push_back(v);
				_numVertexes++;
			}

			//Prec: u y v pertenecen al grafo
			//Añade un lado al grafo a partir de sus dos vértices y su peso. Esto se reflejará sólo en la matriz de adyacencia
			void GraphMatrix::addEdge(const double & data, const Vertex & u, const Vertex & v){
				assert( searchVertex(u.getData()) && (_cursorV!=NULL) );
				assert( searchVertex(v.getData()) && (_cursorV!=NULL) );

				if(isDirected()){
					_matrixV[u.getLabel()][v.getLabel()]=data;
					_numEdges++;
				}else{
					_matrixV[u.getLabel()][v.getLabel()]=data;
					_matrixV[v.getLabel()][u.getLabel()]=data;
					_numEdges++;
				}
			}
					
			//Busca un vertice a partir de su data, colocando el cursor en dicho vértice
			bool GraphMatrix::searchVertex(const std::string &data){
				bool retVal=false;
				
				for (unsigned int i = 0; i < _vectorV.capacity() && retVal==false; ++i)
				{
					if(_vectorV[i].getData() ==data){
						_cursorV=&_vectorV[i];
						retVal=true;
					}
				}

				return retVal;
			}
      
			//Prec: u pertenece al grafo
			//Lleva el cursor a un vertice a partir de dicho vertice
			void GraphMatrix::goTo(const Vertex & u){
				searchVertex(u.getData());
				assert(hasCurrEdge());

				for (unsigned int i = 0; i < _vectorV.capacity(); ++i)
				{
					if(_vectorV[i].getData()==u.getData()){
						_cursorV=&_vectorV[i];
					}
				}
			}
			
			//Prec: 0 <= idx < numVertexes()
			//lleva el cursor a un vértice a partir de la posicion de dicho vertice
			void GraphMatrix::goTo(const unsigned int &idx){
				assert(0<=idx && idx<numVertexes());
				_cursorV=&_vectorV[idx];
			}
			
			//Prec: u y v pertenecen al grafo
			//Lleva el cursor a un lado a partir de sus vertices
			void GraphMatrix::searchEdge(const Vertex & u, const Vertex & v){
				assert( searchVertex(u.getData()) && (_cursorV!=NULL) );
				assert( searchVertex(v.getData()) && (_cursorV!=NULL) );

				Edge aux;

				_cursorE->setData(_matrixV[u.getLabel()][v.getLabel()]);
				_cursorE->setFirst(u);
				_cursorE->setSecond(v);
			}

			
			//Vertex cursor
			//Lleva el cursor al primer vertice
			void GraphMatrix::beginVertex(){
				_cursorV=&_vectorV[0];
			}
			
			//Avanza el cursor al siguiente vertice
			void GraphMatrix::nextVertex(){
				_cursorV++;
			}
			
			//Comprueba si el cursor ha sobrepasado su última posicion válida
			bool GraphMatrix::afterEndVertex() const{
				bool retVal=true;
				
				if(_cursorV!=&_vectorV[capacity()]){
					retVal=false;
				}

				return(retVal);

			}
			
			//Edge cursor
			//Lleva el cursor al primer lado que sale del vertice u
			void GraphMatrix::beginEdge(const Vertex & u){
				bool encontrado=false;
				Edge* aux=new Edge;
				aux->setFirst(u);

				for (unsigned int i = 0; i <capacity() && encontrado==false; i++)
				{
					if (_matrixV[u.getLabel()][i]>0 && _matrixV[u.getLabel()][i]<std::numeric_limits<float>::infinity())
					{
						aux->setSecond(_vectorV[i]);
						aux->setData(_matrixV[u.getLabel()][i]);
						encontrado=true;
					}
				}
				if(encontrado==true)
					_cursorE=aux;
				else
					_cursorE=NULL;
			}
			
			//Avanza el cursor al siguiente lado que sale de currEdge().first()
			void GraphMatrix::nextEdge(){
				bool encontrado=false;
				Edge* aux=new Edge;

				
				//cout<<currEdge().first().getData()<<", "<<currEdge().second().getData()<<endl;

				for (unsigned int i = currEdge().second().getLabel()+1; i <capacity() && encontrado==false; ++i)
				{
						//cout<<"matrix "<<_matrixV[currEdge().first().getLabel()][i]<<endl;
						if (_matrixV[currEdge().first().getLabel()][i]>0 && _matrixV[currEdge().first().getLabel()][i]<std::numeric_limits<float>::infinity())
						{
							//cout<<"if "<<_matrixV[currEdge().first().getLabel()][i]<<endl;
							aux->setFirst(currEdge().first());
							aux->setSecond(_vectorV[i]);
							aux->setData(_matrixV[aux->first().getLabel()][i]);
							encontrado=true;
						}
				}
				if(encontrado==true){
					_cursorE=aux;
				}else{
					_cursorE=NULL;
				}
			}
			
			//Comprueba si el cursor ha sobrepasado su última posicion válida para los lados que salen de currEdge().first()
			bool GraphMatrix::afterEndEdge(){
			
				if (_cursorE==NULL){
					return(true);
				}else{
					return(false);
				}
			}
