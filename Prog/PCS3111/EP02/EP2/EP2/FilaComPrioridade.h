#ifndef FILACOMPRIORIDADE_H
#define FILACOMPRIORIDADE_H

#include "Fila.h"

class FilaComPrioridade : public Fila {
public:
	FilaComPrioridade(int tamanho);
	virtual ~FilaComPrioridade();

	virtual void enqueue(Datagrama* d, bool prioritario);
	
	//Redefinicoes
	virtual void enqueue(Datagrama* d);
	virtual Datagrama* dequeue();

private:
	Fila* prioritarios;
	Fila* naoPrioritarios;

};

#endif
