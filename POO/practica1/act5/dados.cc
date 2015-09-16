#include<cstdlib>
#include<ctime>
#include"dados.h"

void Dados::lanzamiento(){

	dado1_ = rand()%6+1;
	lanz1_++;
	suma1_ +=dado1_;
	dado2_ = rand()%6+1;
	lanz2_++;
	suma2_ += dado2_;

	vector1_[getLanzamientos1()%5]=getDado1();
	vector2_[getLanzamientos2()%5]=getDado2();
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
		lanz1_++;
		suma1_ += num;
		vector1_[getLanzamientos1()%5]=getDado1();
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
		lanz2_++;
		suma2_ += num;
		vector2_[getLanzamientos2()%5]=getDado2();
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

	lanz1_=0;
	lanz2_=0;

	suma1_=0;
	suma2_=0;	

	srand(time(NULL));

}


int Dados::getLanzamientos1(){
	return(lanz1_);
}

int Dados::getLanzamientos2(){
	return(lanz2_);
}

float Dados::getMedia1(){
	if(getLanzamientos1()==0)
		return(0);
	else
		return((float)suma1_/(float)lanz1_);
}

float Dados::getMedia2(){

	if(getLanzamientos2()==0)
		return(0);
	else
		return((float)suma2_/(float)lanz2_);
}


void Dados::getUltimos1(int * num){


	
	for(int i=0; i<5; i++){
		num[i] = vector1_[i];
	}
	

} 

void Dados::getUltimos2(int*num){

	for(int i=0; i<5; i++){
		num[i] = vector2_[i];
	}
}
