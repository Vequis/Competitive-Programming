#include <iostream>
#include "Datagrama.h"

Datagrama::Datagrama(int origem, int destino, string dado) {
    this->origem = origem;
    this->destino = destino;
    this->dado = dado;
}

Datagrama::~Datagrama() {
}

int Datagrama::getOrigem() {
    return this->origem;
}

int Datagrama::getDestino() {
    return this->destino;
}
string Datagrama::getDado() {
    return this->dado;
}

void Datagrama::imprimir(){
    cout << "O pacote de " << getOrigem() << " a " << getDestino() << " contém o dado " << getDado() << endl;
}