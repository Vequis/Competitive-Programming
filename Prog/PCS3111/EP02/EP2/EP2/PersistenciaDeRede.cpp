#include "PersistenciaDeRede.h"
#include <fstream>
#include <iostream>

using namespace std;

PersistenciaDeRede::PersistenciaDeRede(string arquivo) {
	this->arquivo = arquivo;
}

PersistenciaDeRede::~PersistenciaDeRede() {
}

Rede* PersistenciaDeRede::carregar() {
	ifstream input;
	input.open(arquivo);

	if (input.fail()) {
		throw new logic_error("Arquivo inexistente");
	}

	Rede* rede = new Rede();

	int qtdeRoteadores;
	input >> qtdeRoteadores;

	for (int i = 0; i < qtdeRoteadores; ++i) {
		char c;
		input >> c;

		int endereco;
		input >> endereco;
		
		if (c == 'r') {
			rede->adicionar(new Roteador(endereco));
		} else {
			RoteadorComQoS* rqos = new RoteadorComQoS(endereco);
			int qtdePriorizados;

			input >> qtdePriorizados;

			for (int j = 0; j < qtdePriorizados; j++) {
				int enderecoPriorizado;
				input >> enderecoPriorizado;

				rqos->priorizar(enderecoPriorizado);
			}

			rede->adicionar(rqos);
		} 
	}

	int qtdeHospedeiros;
	input >> qtdeHospedeiros;

	//<endereço> <gateway> <atraso> <quantidade de chats> <chat1> <chat2> ...
	for (int i = 0; i < qtdeHospedeiros; ++i) {
		int endereco;
		int gateway;
		int atraso;
		int qtdeChats;

		input >> endereco >> gateway >> atraso >> qtdeChats;

		Roteador* gatewayPadrao = dynamic_cast<Roteador*>(rede->getNo(gateway));

		Hospedeiro* h = new Hospedeiro(endereco, gatewayPadrao, atraso);

		for (int j = 0; j < qtdeChats; ++j) {
			//<porta> <endereço de destino> <porta de destino>
			int porta, endDestino, portaDestino;
			input >> porta >> endDestino >> portaDestino;

			h->adicionarChat(porta, endDestino, portaDestino);
		}

		rede->adicionar(h);
	}

	for (int i = 0; i < qtdeRoteadores; ++i) {
		int roteador, padrao, atPadrao, qtdeMapeamentos;

		input >> roteador >> padrao >> atPadrao >> qtdeMapeamentos;

		Roteador* r = dynamic_cast<Roteador*>(rede->getNo(roteador));

		r->setPadrao(rede->getNo(padrao), atPadrao);

		for (int j = 0; j < qtdeMapeamentos; ++j) {
			int endDestino, endAdjacente, atraso;
			input >> endDestino >> endAdjacente >> atraso;

			r->mapear(endDestino, rede->getNo(endAdjacente), atraso);
		}
	}

	if (input.fail()) {
		throw new logic_error("Falha na leitura");
	}

	return rede;

	input.close();
}