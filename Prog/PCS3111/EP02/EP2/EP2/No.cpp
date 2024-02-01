#include "No.h"
#include <stdexcept>
#include <iostream>

No::No(int endereco) : endereco(endereco) {
	fila = new Fila(TAMANHO_FILA);
}

No::No(int endereco, Fila* fila) : endereco(endereco), fila(fila) {
}

No::~No() {
	delete fila;
}

int No::getEndereco() {
	return this->endereco;
}

void No::receber(Datagrama* d) {
	try {
		fila->enqueue(d);
	} catch (overflow_error* oe) {
		delete d;
		cout << "\tFila em " << getEndereco() << " estourou" << endl;
		delete oe;
	}
}