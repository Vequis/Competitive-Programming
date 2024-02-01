#include "Rede.h"
#include <iostream>

using namespace std;

Rede::Rede(int tamanho) : tamanhoMaximo(tamanho) {
    roteadores = new Roteador*[tamanho];
    quantidade = 0;
}

Rede::~Rede(){
    for(int i=0; i < quantidade; i++){
        delete roteadores[i];
    }
    delete[] roteadores;
}

bool Rede::adicionar(Roteador* r) {
    if (quantidade == tamanhoMaximo) return false;

    for(int i=0; i < quantidade; i++) {
        if (roteadores[i]->getEndereco() == r->getEndereco()) {
            return false;
        }
    }

    roteadores[quantidade] = r;
    quantidade++;
    return true;
}

Roteador* Rede::getRoteador(int endereco) {
    for(int i=0; i < quantidade; i++) {
        if (roteadores[i]->getEndereco() == endereco) {
            return roteadores[i];
        }
    }

    return NULL;
}

int Rede::getQuantidade() {
    return this->quantidade;
}

Roteador** Rede::getRoteadores() {
    Roteador** vetorRoteadores = new Roteador*[this->getQuantidade()];

    for (int i = 0; i < quantidade; i++) {
        vetorRoteadores[i] = roteadores[i];
    }

    return vetorRoteadores;
}

void Rede::imprimir(){
    cout << "Essa rede tem " << quantidade << " roteadores" << endl;
}
