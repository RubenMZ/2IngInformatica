#include<cstdlib>
#include<ctime>
#include"dados.h"

void Dados::lanzamiento(){

	dado1_ = rand()%6+1;
	dado2_ = rand()%6+1;
}

int Dados::getDado1(){
	return(dado1_);
}


int Dados::getDado2(){
	return(dado2_);
}

bool Dados::setDado1(int num){

	if((num<=6)&&(num>=1))
	{
		dado1_ = num;
		return(true);
	}else
	{
		return(false);

	}	

}

bool Dados::setDado2(int num){

	if((num<=6)&&(num>=1))
	{
		dado2_ = num;
		return(true);
	}else
	{
		return(false);

	}

}


int Dados::getSuma(){

	return(dado1_+dado2_);

}


Dados::Dados(){

	dado1_=1;
	dado2_=1;
	
	srand(time(NULL));

}


