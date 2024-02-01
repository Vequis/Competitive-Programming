#include "RoteadorComQoS.h"
#include <stdexcept>
#include <iostream>

using namespace std;

RoteadorComQoS::RoteadorComQoS(int endereco) :
	Roteador(endereco, new FilaComPrioridade(TAMANHO_FILA)) {
	destinosPriorizados = new vector<int>();
}

RoteadorComQoS::~RoteadorComQoS() {
	delete destinosPriorizados;
}

void RoteadorComQoS::priorizar(int destino) {
	destinosPriorizados->push_back(destino);
}

vector<int>* RoteadorComQoS::getDestinosPriorizados() {
	return destinosPriorizados;
}

void RoteadorComQoS::receber(Datagrama* d) {
	try {
		bool priorizado = false;
		for (int i = 0; i < (int)destinosPriorizados->size(); i++) {
			if (destinosPriorizados->at(i) == d->getDestino()) {
				priorizado = true;
			}
		}

		FilaComPrioridade* fcp = dynamic_cast<FilaComPrioridade*>(fila);

		fcp->enqueue(d, priorizado);
	} catch (overflow_error* oe) {
		delete d;
		cout << "\tFila em " << getEndereco() << " estourou" << endl;
		delete oe;
	}
}
