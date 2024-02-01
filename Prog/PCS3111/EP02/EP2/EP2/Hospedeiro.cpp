#include "Hospedeiro.h"
#include <stdexcept>
#include <iostream>

Hospedeiro::Hospedeiro(int endereco, Roteador* gateway, int atraso) :
	No(endereco), gateway(gateway), atraso(atraso) {
	chats = new vector<Chat*>();
}

Hospedeiro::~Hospedeiro() {
	for (int i = 0; i < (int)chats->size(); i++) {
		delete chats->at(i);
	}

	delete chats;
}

void Hospedeiro::adicionarChat(int porta, int enderecoDestino, int portaDestino) {
	for (int i = 0; i < (int)chats->size(); i++) {
		if (chats->at(i)->getPorta() == porta) {
			throw new logic_error("Porta ocupada");
		}
	}

	Chat* atual = new Chat(this, porta, enderecoDestino, portaDestino);
	chats->push_back(atual);
}

vector<Chat*>* Hospedeiro::getChats() {
	return chats;
}

Chat* Hospedeiro::getChat(int porta) {
	for (int i = 0; i < (int)chats->size(); i++) {
		if (chats->at(i)->getPorta() == porta) {
			return chats->at(i);
		}
	}

	return NULL;
}

Evento* Hospedeiro::processar(int instante) {
	if (fila->isEmpty()) {
		return NULL;
	}

	cout << "Hospedeiro " << endereco << endl;

	Datagrama* atual = fila->dequeue();

	if (atual->getDestino() == endereco) {
		int portaDestino = atual->getSegmento()->getPortaDeDestino();

		for (int i = 0; i < (int)chats->size(); i++) {
			if (chats->at(i)->getPorta() == portaDestino) {
				chats->at(i)->receber(atual);

				cout << "\tMensagem Recebida" << endl;
				cout << chats->at(i)->getTextoCompleto();

				return NULL;
			}
		}

		cout << "\tSem chat: ";
		atual->imprimir();

		return NULL;
	
	} else {
		cout << "\tMensagem Enviada" << endl;

		return new Evento(instante + atraso, gateway, atual);
	}
}

void Hospedeiro::imprimir() {
}