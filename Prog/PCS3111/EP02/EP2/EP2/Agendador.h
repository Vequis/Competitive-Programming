#ifndef AGENDADOR_H
#define AGENDADOR_H

#include "Evento.h"
#include "Roteador.h"
#include "Rede.h"

class Agendador{
private:
    int instanteAtual;
    Rede *rede;
    int tamanhoMaximo;
    int quantidade; // de eventos alocados
    Evento **eventos; //PriorityQueue 0-indexado : Estrutura Heap

protected:
    //Funcoes do Heap
    int pai(int i);
    int filhoDireito(int i);
    int filhoEsquerdo(int i);
    void minHeapify(int i); //O topo da pilha sempre terá o menor instante
    void inserirHeap(Evento *e);
    void removeTopoHeap();

public:
    Agendador(int instanteInicial, Rede* rede, int tamanho);
    virtual ~Agendador();

    virtual bool agendar(int instante, No* n, Datagrama* d);
    virtual void processar();
    virtual int getInstante();

};

#endif
