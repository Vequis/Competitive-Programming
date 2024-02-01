#include "TabelaDeRepasse.h"

TabelaDeRepasse::TabelaDeRepasse(int tamanho) : tamanho(tamanho){
    destinos = new int[tamanho];
    Roteador **adjacentes = new Roteador*[tamanho];
    atrasos = new int[tamanho];   
    
    padrao = nullptr; 
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
    // A função sairá deste for se, e somente se, o endereco não esteja na tabela

    destinos[qtd_adjacentes] = endereco;
    adjacentes[qtd_adjacentes] = endereco;
    destinos[qtd_adjacentes] = endereco;
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
//Deixar os vetores ordenados e sempre fazer busca binária
Roteador* TabelaDeRepasse::getProximoSalto(int endereco, int& atraso){
    for (int i = 0; i < qtd_adjacentes; i++){
        if (destinos[i] == endereco){
            *atraso = atrasos[i];
            return adjacentes[i];
        }
    }

    //Roteador Padrão
    *atraso = atraso_padrao;
    return padrao;
}

void TabelaDeRepasse::imprimir() {
    // cout << "Os roteadores adjacentes a este roteador são: " << endl;
    // for(int i = 0; i < n; i++)
}

