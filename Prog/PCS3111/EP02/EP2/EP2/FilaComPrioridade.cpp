#include "FilaComPrioridade.h"
#include <stdexcept>

FilaComPrioridade::FilaComPrioridade(int tamanho) : Fila(tamanho) {
	prioritarios = new Fila(10);
	naoPrioritarios = new Fila(10);
}

FilaComPrioridade::~FilaComPrioridade() {
	delete prioritarios;
	delete naoPrioritarios;
}

void FilaComPrioridade::enqueue(Datagrama* d, bool prioritario) {
	if (qtdeAlocados == tamanho) {
		throw new overflow_error("Fila prioritaria cheia");
	}

	qtdeAlocados++;

	if (prioritario) {
		prioritarios->enqueue(d);
	} else {
		naoPrioritarios->enqueue(d);
	}
}

void FilaComPrioridade::enqueue(Datagrama* d) {
	enqueue(d, 0);
}

Datagrama* FilaComPrioridade::dequeue() {
	
	if (qtdeAlocados == 0)
		throw new underflow_error("Fila com Prioridade vazia");

	qtdeAlocados--;

	if (!prioritarios->isEmpty()) {
		return prioritarios->dequeue();
	} 

	return naoPrioritarios->dequeue();

}
