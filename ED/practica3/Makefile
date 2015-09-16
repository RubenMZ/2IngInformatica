OBJECTS = main.o generarpersona.o persona.o gestorFichero.o clave.o funcionesArbol.o
INCLUDES = edi_LinkedList.hpp edi_LinkedNode.hpp edi_List.hpp asignatura.hpp edi_LinkedBinaryTree.hpp edi_BinaryTree.hpp edi_LinkedBinaryTreeNode.hpp edi_LinkedOrderedBinaryTree.hpp

main: $(OBJECTS)
	g++ -g $(OBJECTS) -o main

main.o: main.cpp $(INCLUDES)
	g++ -g -c main.cpp

persona.o: persona.hpp persona.cpp 
	g++ -g -c persona.cpp

generarpersona.o: generarpersona.cpp generarpersona.hpp
	g++ -g -c generarpersona.cpp

gestorFichero.o: gestorFichero.cpp gestorFichero.hpp
	g++ -g -c gestorFichero.cpp

clave.o: clave.cpp clave.hpp
	g++ -g -c clave.cpp

funcionesArbol.o: funcionesArbol.cpp funcionesArbol.hpp
	g++ -g -c funcionesArbol.cpp

clean: $(OBJECTS)
	rm -f $(OBJECTS)