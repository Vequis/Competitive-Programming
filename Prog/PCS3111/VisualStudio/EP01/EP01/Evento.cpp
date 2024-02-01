#include "Evento.h"
#include <iostream>

using namespace std;

Evento::Evento(int instante, Roteador* destino, Datagrama* d) :
instante(instante), destino(destino), d(d) {}

Evento::~Evento(){
}

int Evento::getInstante() {
    return instante;
}

Roteador* Evento::getDestino() {
    return destino;
}

Datagrama* Evento::getDatagrama() {
    return d;
}

void Evento::imprimir() {
    cout << "Este evento representa a transferência de um pacote para o roteador " <<
    this->getDestino()->getEndereco() << " no momento " << getInstante() << endl;
}
