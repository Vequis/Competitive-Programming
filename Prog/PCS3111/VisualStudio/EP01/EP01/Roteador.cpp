#include "Roteador.h"
#include <iostream>

using namespace std;

Roteador::Roteador(int endereco) : endereco(endereco) {
    fila = new Fila(TAMANHO);
    tabela = new TabelaDeRepasse(TAMANHO);
}

Roteador::~Roteador() {
    delete fila;
    delete tabela;
}

bool Roteador::mapear(int endereco, Roteador* adjacente, int atraso) {
    return tabela->mapear(endereco, adjacente, atraso);
}

void Roteador::setPadrao(Roteador* padrao, int atraso) {
    tabela->setPadrao(padrao, atraso);
}

int Roteador::getEndereco() {
    return this->endereco;
}

void Roteador::receber(Datagrama* d){
    if (fila->enqueue(d) == false){
        cout << "\tFila em " << endereco << " estourou" << endl;
    }
}

Evento* Roteador::processar(int instante){
    if (fila->isEmpty()){
        return NULL;
    } else {
        Datagrama *d = fila->dequeue();

        cout << "Roteador " << endereco << endl;

        if (d->getDestino() == endereco){
            cout << "\tRecebido: " << d->getDado() << endl;

            delete d;
            return NULL;
        } else { //destino != endereco
            int atraso = 0;
            Roteador *proxSalto = tabela->getProximoSalto(d->getDestino(), atraso);

            if (proxSalto == NULL) {
                cout << "\tSem proximo: ";
                d->imprimir();

                delete d;
                return NULL;
            } else { // proxSalto != NULL
                cout << "\tRepassado para " << proxSalto->getEndereco() << "(instante " << instante+atraso << "): ";
                d->imprimir();

                Evento *atual = new Evento(instante + atraso, proxSalto, d);

                return atual;
            }
        }
    }
}

void Roteador::imprimir(){
    cout << "Roteador de endereco " << endereco << " tem " << fila->getSize() << " datagramas" << endl;
}
