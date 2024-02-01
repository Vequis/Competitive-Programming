#include "Chat.h"
#include <stdexcept>
#include <iostream>

Chat::Chat(Hospedeiro* h, int porta, int enderecoDestino, int portaDestino) :
	h(h), porta(porta), enderecoDestino(enderecoDestino),
	portaDestino(portaDestino) {
	
	textoCompleto = "";
	
	if (h == NULL) {
		throw new invalid_argument("Sem hospedeiro");
	}
}	

Chat::~Chat() {
}

int Chat::getPorta() {
	return porta;
}

void Chat::enviar(string texto) {
	Segmento* s = new Segmento(porta, portaDestino, texto);
	Datagrama* d = new Datagrama(h->getEndereco(), enderecoDestino, s);

	h->receber(d);

	textoCompleto += "\t\tEnviado: " + texto + '\n';
}

void Chat::receber(Datagrama* d) {
	string texto = d->getSegmento()->getDado();
	textoCompleto += "\t\tRecebido: " + texto + '\n';

	delete d;
}

string Chat::getTextoCompleto() {
	return textoCompleto;
}

void Chat::imprimir() {
	cout << "Chat" << endl;
}