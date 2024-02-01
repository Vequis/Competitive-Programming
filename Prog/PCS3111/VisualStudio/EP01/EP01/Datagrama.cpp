#include <iostream>
#include "Datagrama.h"

Datagrama::Datagrama(int origem, int destino, string dado) :
origem(origem), destino(destino), dado(dado) {
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

void Datagrama::imprimir() {
    cout << "Origem: " << origem << ", Destino: " << destino << ", " << dado << endl;
}
