#ifndef SEGMENTO_H
#define SEGMENTO_H

#include <string>

using namespace std;

class Segmento {
private:
	int portaDeOrigem;
	int portaDeDestino;
	string dado;
public:
	Segmento(int portaDeOrigem, int portaDeDestino, string dado);
	virtual ~Segmento();

	virtual int getPortaDeOrigem();
	virtual int getPortaDeDestino();
	virtual string getDado();
	
	virtual void imprimir();
};

#endif