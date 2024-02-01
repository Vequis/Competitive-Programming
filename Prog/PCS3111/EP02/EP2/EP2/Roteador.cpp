#include "Roteador.h"
#include <iostream>

using namespace std;

Roteador::Roteador(int endereco) : No(endereco) {
    tabela = new TabelaDeRepasse(TAMANHO_TABELA);
}

Roteador::Roteador(int endereco, Fila* fila) : No(endereco, fila) {
    tabela = new TabelaDeRepasse(TAMANHO_TABELA);
}

Roteador::~Roteador() {
    delete tabela;
}

void Roteador::mapear(int endereco, No* adjacente, int atraso) {
    return tabela->mapear(endereco, adjacente, atraso);
}

void Roteador::setPadrao(No* padrao, int atraso) {
    tabela->setPadrao(padrao, atraso);
}

Evento* Roteador::processar(int instante){
    if (fila->isEmpty()){
        return NULL;
    } else {
        Datagrama *d = fila->dequeue();

        cout << "Roteador " << endereco << endl;

        if (d->getDestino() == endereco){
            cout << "\tRecebido: " << d->getSegmento()->getDado() << endl;

            delete d;
            return NULL;
        } else { //destino != endereco
            int atraso = 0;
            No *proxSalto = tabela->getProximoSalto(d->getDestino(), atraso);

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
