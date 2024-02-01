#include "TabelaDeRepasse.h"
#include <iostream>

using namespace std;

TabelaDeRepasse::TabelaDeRepasse(int tamanho) : tamanho(tamanho){
    destinos = new int[tamanho];
    adjacentes = new Roteador*[tamanho];
    atrasos = new int[tamanho];

    qtd_adjacentes = 0;
    padrao = NULL;
    atraso_padrao = 0;
}

TabelaDeRepasse::~TabelaDeRepasse(){
    delete[] destinos;
    delete[] adjacentes;
    delete[] atrasos;
}

bool TabelaDeRepasse::mapear(int endereco, Roteador* adjacente, int atraso){
    if(qtd_adjacentes == tamanho) return false;

    for (int i = 0; i < qtd_adjacentes; i++) {
        if (destinos[i] == endereco) return false;
    }
    // A função sairá deste for se, e somente se, o endereco não estiver na tabela

    destinos[qtd_adjacentes] = endereco;
    adjacentes[qtd_adjacentes] = adjacente;
    atrasos[qtd_adjacentes] = atraso;
    qtd_adjacentes++;
    return true;
}

Roteador** TabelaDeRepasse::getAdjacentes() {
    return adjacentes;
}

int TabelaDeRepasse::getQuantidadeDeAdjacentes() {
    return qtd_adjacentes;
}

void TabelaDeRepasse::setPadrao(Roteador* padrao, int atraso) {
    this->padrao = padrao;
    this->atraso_padrao = atraso;
}

//Irei propor uma loucura!!
//Deixar os vetores ordenados e sempre fazer busca binária ??
//
//Atualizacao 18/10: eh uma loucura!! Definitivamente não faremos isso!
//Embora a complexidade vah ficar bem melhor...
//Atualizacao 22/10: de fato, nao implementaremos isso
Roteador* TabelaDeRepasse::getProximoSalto(int endereco, int& atraso){
    for (int i = 0; i < qtd_adjacentes; i++){
        if (destinos[i] == endereco){
            atraso = atrasos[i];
            return adjacentes[i];
        }
    }
    //Sairá deste for se, e somente se, não tiver encontrado o endereco especificado

    atraso = atraso_padrao;
    return padrao;
}

void TabelaDeRepasse::imprimir() {
    cout << "Essa tabela mapeia " << this->getQuantidadeDeAdjacentes() << " roteadores adjacentes" << endl;
}

