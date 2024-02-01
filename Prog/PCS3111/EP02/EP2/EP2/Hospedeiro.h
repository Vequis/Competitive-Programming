#ifndef HOSPEDEIRO_H
#define HOSPEDEIRO_H

#include "No.h"
#include "Chat.h"
#include <vector>
#include "Roteador.h"

class Chat;

class Hospedeiro : public No {
public:
	Hospedeiro(int endereco, Roteador* gateway, int atraso);
	virtual ~Hospedeiro();

	virtual void adicionarChat(int porta, int enderecoDestino, int portaDestino);
	virtual vector<Chat*>* getChats();
	virtual Chat* getChat(int porta);

	//Redefinicoes
	virtual Evento* processar(int instante);
	virtual void imprimir();
protected:
	Roteador* gateway;
	int atraso;
	vector<Chat*>* chats;
};

#endif