#include "namespace.h"
#include <iostream>

using namespace std;
using namespace Figura;

double Circulo::PI_=3.14159;


int main(){

	Cuadrado cua(3.0, "Cuadrado");
	Circulo cir(5.0, "Circulo");

	cout<<"El "<<cua.nombre()<<" con area: "<<cir.area()<<" y perimetro "<<cir.perimetro()<<endl;
	cout<<"El "<<cir.nombre()<<" con area: "<<cua.area()<<" y perimetro "<<cua.perimetro()<<endl;


	return 0;
}