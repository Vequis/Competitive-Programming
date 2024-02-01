#ifndef FILA_H
#define FILA_H

#include "Datagrama.h"

class Fila {
private:
    int qtde_alocados;
    int inicio, fim;
    int tamanho;
public:
    Fila(int tamanho); //Construtor
    ~Fila(); //Destrutor
    
    bool enqueue(Datagrama* d); //Insere o datagrama na ultima posição
    Datagrama* dequeue(); //Retira o elemento da frente
    bool isEmpty(); //Informa se a pilha está vazia
    int getSize(); //Retorna o valor de datagramas na fila
    
    void imprimir();
};


#endif