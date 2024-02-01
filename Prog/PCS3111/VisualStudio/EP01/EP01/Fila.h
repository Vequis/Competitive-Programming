#ifndef FILA_H
#define FILA_H

#include "Datagrama.h"

class Fila {
private:
    int qtde_alocados;
    int inicio, fim;
    int tamanho;
    Datagrama **elementos;
public:
    Fila(int tamanho);
    ~Fila();

    bool enqueue(Datagrama* d); //Insere o datagrama na ultima posição
    Datagrama* dequeue(); //Retira o elemento da frente
    bool isEmpty();
    int getSize();

    void imprimir();
};


#endif
