#include "Agendador.h"
#include <iostream>

using namespace std;

Agendador::Agendador(int instanteInicial, Rede* rede, int tamanho) :
instanteAtual(instanteInicial), rede(rede), tamanhoMaximo(tamanho) {
    eventos = new Evento*[tamanho];
    quantidade = 0;
}

Agendador::~Agendador() {
    for(int i = 0; i < quantidade; i++) {
        delete eventos[i];
    }

    delete[] eventos;
}

bool Agendador::agendar(int instante, No* n, Datagrama* d) {
    if (quantidade == tamanhoMaximo) return false;

    Evento *atual = new Evento(instante, n, d);
    
    inserirHeap(atual);
}

void Agendador::processar() {

    //Enquanto o instante do topo <= instanteAtual
    while (quantidade > 0 && eventos[0]->getInstante() <= instanteAtual) {
        No* rotAtual = eventos[0]->getDestino();
        Datagrama* dAtual = eventos[0]->getDatagrama();
        rotAtual->receber(dAtual);

        this->removeTopoHeap();
    }

    list<No*>* nos = rede->getNos();
    list<No*>::iterator it;

    for (it = nos->begin(); it != nos->end(); ++it) {
        Evento *atual = (*it)->processar(instanteAtual);
        //Se o roteador analisado não possuir nenhum evento
        // a ser processado, então atual = NULL;
        if (atual != NULL) {
            this->agendar(atual->getInstante(), atual->getDestino(), atual->getDatagrama());
        }
    }

    instanteAtual++;
}

int Agendador::getInstante() {
    return this->instanteAtual;
}

//Funcoes Heap

int Agendador::pai(int i) {
    return (i - 1) / 2;
}

int Agendador::filhoEsquerdo(int i) {
    return 2 * i + 1;
}

int Agendador::filhoDireito(int i) {
    return 2 * i + 2;
}

void Agendador::minHeapify(int i) {
    int l = filhoEsquerdo(i);
    int r = filhoDireito(i);

    int menor = i;

    if (l < quantidade && eventos[l]->getInstante() < eventos[menor]->getInstante()) {
        menor = l;
    }

    if (r < quantidade && eventos[r]->getInstante() < eventos[menor]->getInstante()) {
        menor = r;
    }

    if (menor != i) {
        Evento* temp = eventos[i];
        eventos[i] = eventos[menor];
        eventos[menor] = temp;
        this->minHeapify(menor);
    }
}

void Agendador::inserirHeap(Evento* e) {
    int i = quantidade; //indice atual do evento e
    
    eventos[i] = e;

    while (i>0 && e->getInstante() < eventos[pai(i)]->getInstante()) {
        eventos[i] = eventos[pai(i)];
        eventos[pai(i)] = e;

        i = pai(i);
    }

    quantidade++;
}

void Agendador::removeTopoHeap() {
    delete eventos[0];

    quantidade--;
    eventos[0] = eventos[quantidade];
    minHeapify(0);
}
