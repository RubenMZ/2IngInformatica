#include"dados.h"
#include<iostream>

using namespace std;

int main(){

	Dados d;
	int valor1, valor2;

	cout<<"Bienvenido al juego de los dados.\n\n";

	d.lanzamiento();

	cout<<"Los valores de los dados es: "<<d.getDado1()<<" y "<<d.getDado2()<<" cuya suma es: "<<d.getSuma()<<"\n";

	cout<<"Inserta un valor para tus dados.\n";
	cout<<"Primero: ";
	cin>>valor1;
	cout<<"Segundo: ";
	cin>>valor2;
	
	if(d.setDado1(valor1)){
		cout<<"Se inserto correctamente el dado1.\n";
	}else{
		cout<<"El dado1 no puede tener ese valor.\n";

	}

	if(d.setDado2(valor2)){
		cout<<"Se inserto correctamente el dado2.\n";
	}else{
		cout<<"El dado2 no puede tener ese valor.\n";

	}

	cout<<"Los valores de los dados actualizados son: "<<d.getDado1()<<" y "<<d.getDado2()<<" cuya suma es: "<<d.getSuma()<<"\n";

	



return 0;
}
