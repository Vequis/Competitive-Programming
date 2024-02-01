#include "Fila.h"
#include <iostream>

using namespace std;

Fila::Fila(int tamanho){
    this->tamanho = tamanho;
    inicio = 0; //Primeira posição ocupada no vetor
    fim = 0; //Primeira posição livre no vetor -> 0-indexado
    qtde_alocados = 0;
    elementos = new Datagrama*[tamanho];
}

Fila::~Fila(){
    for(int i=inicio; i!=fim; i = (i+1)%tamanho){
        delete elementos[i];
    }
    delete[] elementos;
}

bool Fila::enqueue(Datagrama* d){
    if (qtde_alocados == tamanho){
        //Overflow
	    return false;
    } else {
        elementos[fim] = d;

        fim++;
        qtde_alocados++;
        if (fim == tamanho) fim = 0;
	    return true;
    }
}

Datagrama* Fila::dequeue(){
    if (this->isEmpty()){
        //Underflow
	    return NULL;
    } else {
        Datagrama *retorno = elementos[inicio];

        inicio++;
        qtde_alocados--;
        if (inicio == tamanho) inicio = 0; //Evitando ML

	    return retorno;
    }
}

bool Fila::isEmpty(){
    return (qtde_alocados == 0);
}

int Fila::getSize(){
    return this->qtde_alocados;
}

void Fila::imprimir(){
    cout << "Imprimindo Fila" << endl;
    for(int i=inicio; i!=fim; i = (i+1)%tamanho){
        cout << i << endl;
        cout << elementos[i]->getDado() << endl;
    }
}
