#ifndef REDE_H
#define REDE_H

#include "Roteador.h"

class Rede {
private:
    int tamanhoMaximo;
    int quantidade; // de roteadores alocados
    Roteador **roteadores;
public:
    Rede(int tamanho);
    ~Rede();

    bool adicionar(Roteador* r);
    Roteador* getRoteador(int endereco);

    Roteador** getRoteadores();
    int getQuantidade();

    void imprimir();
};

#endif
