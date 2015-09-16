#ifndef DADOS_H
#define DADOS_H

class Dados{

	private:
		int dado1_, dado2_;

	public: 
		void lanzamiento();
		int getDado1(), getDado2();
		bool setDado1(int num), setDado2(int num);
		int getSuma();
		Dados();
		

};

#endif
