#include <iostream>
#include "Datagrama.h"

Datagrama::Datagrama(int origem, int destino, Segmento* conteudo) :
origem(origem), destino(destino), conteudo(conteudo) {
}

Datagrama::~Datagrama() {
    delete conteudo;
}

int Datagrama::getOrigem() {
    return this->origem;
}

int Datagrama::getDestino() {
    return this->destino;
}

Segmento* Datagrama::getSegmento() {
    return this->conteudo;
}

void Datagrama::imprimir() {
    cout << 
        "Origem: " << origem << ':' << conteudo->getPortaDeOrigem() <<
        ", Destino: " << destino << ':' << conteudo->getPortaDeDestino() <<
        ", " << conteudo->getDado() << endl;
}
