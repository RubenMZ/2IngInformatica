#ifndef DADOS_H
#define DADOS_H

class Dados{

	private:
		int dado1_, dado2_;
		int lanz1_, lanz2_;
		int suma1_, suma2_;
		int vector1_[5], vector2_[5];

	public: 
		void lanzamiento();
		int getDado1(), getDado2();
		bool setDado1(int num), setDado2(int num);
		int getSuma();
		Dados();
		int getLanzamientos2(), getLanzamientos1();
		float getMedia1(), getMedia2();
		void getUltimos1(int* num), getUltimos2(int* num);

};

#endif
