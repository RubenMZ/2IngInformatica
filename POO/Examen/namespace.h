#ifndef NAMESPACE_H
#define NAMESPACE_H

#include <string>

using namespace std;


namespace Figura{

class Figura{

	private: 
		string nombre_;

	public:
		inline Figura(string n):nombre_(n){};
		inline string nombre(){return(nombre_);};
		virtual double area()=0;
		virtual double perimetro()=0;
};

class Cuadrado:public Figura{

	private:
		double lado_;
	public:
		inline Cuadrado(double lado, string n):Figura(n),lado_(lado){};
		virtual double area();
		virtual double perimetro();
};




class Circulo:public Figura{

	private:
		double radio_;
		static double PI_;
	public:
		inline Circulo(double radio, string n):Figura(n),radio_(radio){};
		virtual double area();
		virtual double perimetro();
};


}

#endif