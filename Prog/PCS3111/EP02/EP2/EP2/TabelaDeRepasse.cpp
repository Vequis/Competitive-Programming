#include "TabelaDeRepasse.h"
#include <iostream>
#include <stdexcept>

using namespace std;

TabelaDeRepasse::TabelaDeRepasse(int tamanho) : tamanho(tamanho){
    if (tamanho <= 0) {
        throw new invalid_argument("Tamanho invalido");
    }
    
    destinos = new int[tamanho];
    adjacentes = new No*[tamanho];
    atrasos = new int[tamanho];

    qtdeAdjacentes = 0;
    padrao = NULL;
    atrasoPadrao = 0;
}

TabelaDeRepasse::~TabelaDeRepasse(){
    delete[] destinos;
    delete[] adjacentes;
    delete[] atrasos;
}

void TabelaDeRepasse::mapear(int endereco, No* adjacente, int atraso){
    if (qtdeAdjacentes == tamanho) {
        throw new overflow_error("Tabela de Repasse cheia");
    }

    for (int i = 0; i < qtdeAdjacentes; i++) {
        if (destinos[i] == endereco) {
            throw new invalid_argument("Endereco repetido");
        }
    }
    // A função sairá deste for se, e somente se, o endereco não estiver na tabela

    destinos[qtdeAdjacentes] = endereco;
    adjacentes[qtdeAdjacentes] = adjacente;
    atrasos[qtdeAdjacentes] = atraso;
    qtdeAdjacentes++;
}

No** TabelaDeRepasse::getAdjacentes() {
    return adjacentes;
}

int TabelaDeRepasse::getQuantidadeDeAdjacentes() {
    return qtdeAdjacentes;
}

void TabelaDeRepasse::setPadrao(No* padrao, int atraso) {
    this->padrao = padrao;
    this->atrasoPadrao = atraso;
}

No* TabelaDeRepasse::getProximoSalto(int endereco, int& atraso){
    for (int i = 0; i < qtdeAdjacentes; i++){
        if (destinos[i] == endereco){
            atraso = atrasos[i];
            return adjacentes[i];
        }
    }
    //Sairá deste for se, e somente se, não tiver encontrado o endereco especificado

    atraso = atrasoPadrao;
    return padrao;
}

void TabelaDeRepasse::imprimir() {
    cout << "Essa tabela mapeia " << this->getQuantidadeDeAdjacentes() << " nos adjacentes" << endl;
}

