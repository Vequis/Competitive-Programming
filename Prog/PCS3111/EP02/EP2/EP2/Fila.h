#ifndef FILA_H
#define FILA_H

#include "Datagrama.h"

class Fila {
protected:
    int qtdeAlocados;
    int inicio, fim;
    int tamanho;
    Datagrama **elementos;
public:
    Fila(int tamanho);
    virtual ~Fila();

    virtual void enqueue(Datagrama* d); //Insere o datagrama na ultima posição
    virtual Datagrama* dequeue(); //Retira o elemento da frente
    virtual bool isEmpty();
    virtual int getSize();

    virtual void imprimir();
};

#endif
