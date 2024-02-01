#include "Fila.h"
#include <iostream>
#include <stdexcept>

using namespace std;

Fila::Fila(int tamanho) : tamanho(tamanho) {
    if (tamanho <= 0)
        throw new invalid_argument("Tamanho invalido");

    inicio = 0; //Primeira posição ocupada no vetor
    fim = 0; //Primeira posição livre no vetor -> 0-indexado
    qtdeAlocados = 0;
    elementos = new Datagrama*[tamanho];
}

Fila::~Fila(){
    for(int i=inicio; i!=fim; i = (i+1)%tamanho){
        delete elementos[i];
    }
    delete[] elementos;
}

void Fila::enqueue(Datagrama* d){
    if (qtdeAlocados == tamanho){
        throw new overflow_error("Fila cheia");
    } else {
        elementos[fim] = d;

        fim++;
        qtdeAlocados++;
        if (fim == tamanho) fim = 0;
    }
}

Datagrama* Fila::dequeue(){
    if (this->isEmpty()){
        throw new underflow_error("Fila vazia");
    } else {
        Datagrama *retorno = elementos[inicio];

        inicio++;
        qtdeAlocados--;
        if (inicio == tamanho) inicio = 0; //Evitando ML

	    return retorno;
    }
}

bool Fila::isEmpty(){
    return (qtdeAlocados == 0);
}

int Fila::getSize(){
    return this->qtdeAlocados;
}

void Fila::imprimir(){
    cout << "Imprimindo Fila" << endl;
    for(int i=inicio; i!=fim; i = (i+1)%tamanho){
        cout << i << endl;
        elementos[i]->imprimir();
    }
}
