#ifndef REDE_H
#define REDE_H

#include "Hospedeiro.h"
#include "RoteadorComQoS.h"
#include <list>

class Rede {
private:
    int quantidade; // de roteadores alocados
    list<No*>* nos;
    list<No*>::iterator it; //Declarado globalmente -> mt usado
public:
    Rede();
    virtual ~Rede();

    virtual void adicionar(No* n);
    virtual No* getNo(int endereco);
    virtual list<No*>* getNos();
    virtual list<Hospedeiro*>* getHospedeiros();
    
    virtual void imprimir();
};

#endif
