#ifndef TABELADEREPASSE_H
#define TABELADEREPASSE_H

#include "Roteador.h"

class Roteador;

class TabelaDeRepasse {
private:
    Roteador **adjacentes;
    int *destinos;
    int *atrasos;

    Roteador *padrao;
    int atraso_padrao;

    int tamanho;
    int qtd_adjacentes;
public:
    TabelaDeRepasse(int tamanho);
    ~TabelaDeRepasse();

    bool mapear(int endereco, Roteador* adjacente, int atraso);
    Roteador** getAdjacentes();
    int getQuantidadeDeAdjacentes();

    void setPadrao(Roteador* padrao, int atraso);
    Roteador* getProximoSalto(int endereco, int& atraso);

    void imprimir();
};

#endif
