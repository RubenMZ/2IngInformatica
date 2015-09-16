#include"dados.h"
#include<iostream>

using namespace std;

int main(){

	Dados d;
	int valor1, valor2;
	int vector1[5], vector2[5];

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

	cout<<"La media para dado1: "<<d.getMedia1()<<" despues de "<<d.getLanzamientos1()<<" lanzamientos y la media para dado2: "<<d.getMedia2()<<" despues de "<<d.getLanzamientos2()<<" lanzamientos.\n\n";

	d.lanzamiento();
	d.lanzamiento();
	d.lanzamiento();

	d.getUltimos1(vector1);
	d.getUltimos2(vector2);

	cout<<"\nEl vector del dado1\n";
	for(int i=0; i<5; i++){
		cout<<" "<<vector1[i]<<" ";
	}

	cout<<"\nEl vector del dado2\n";
	for(int i=0; i<5; i++){
		cout<<" "<<vector2[i]<<" ";
	}

	return 0;
}
