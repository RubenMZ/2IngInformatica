#include<iostream>
#include"persona.h"

using namespace std;


int main(){

	Persona p("46068656R");
	string nombre, apellidos, direccion, localidad, provincia, pais;

		cout<<"Introduce tu nombre: ";
		getline(cin,nombre);
		p.setNombre(nombre);
		cout<<"Introduce apellidos: ";
		getline(cin, apellidos);		
		p.setApellidos(apellidos);

		
		
		cout<<"Intruduce direccion: ";
		getline(cin,direccion);
		p.setDireccion(direccion);

		cout<<"Introduce el pais: ";
		cin>>pais;

		p.setPais(pais);

		cout<<"Tu nombre es "<<p.getApellidosyNombre()<<" y vive en "<<p.getDireccion()<<" en el pais "<<p.getPais();

return 0;
}
