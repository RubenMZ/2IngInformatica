#include<iostream>
#include<cstdlib>
#include<ctime>


using namespace std;

int main(){

	int num, aleat;

	srand(time(NULL));
	aleat = rand()%10+1;

	cout<<"Introduce el numero para adivinar: ";
	cin>>num;

	if(num==aleat)
		cout<<"Los numeros son iguales: "<<num<<" = "<<aleat;
	else
	{
		if(num>aleat)
			cout<<"Tu numero es mayor que el generado: "<<num<<" > "<<aleat<<"\n";
		else
			cout<<"Tu numero es menor que el generado: "<<num<<" < "<<aleat<<"\n";
	}
	
	


return 0;
}
