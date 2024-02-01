#ifndef TABELADEREPASSE_H
#define TABELADEREPASSE_H

#include "No.h"

class TabelaDeRepasse {
private:
    No **adjacentes;
    int *destinos;
    int *atrasos;

    No *padrao;
    int atrasoPadrao;

    int tamanho;
    int qtdeAdjacentes;
public:
    TabelaDeRepasse(int tamanho);
    virtual ~TabelaDeRepasse();

    virtual void mapear(int endereco, No* adjacente, int atraso);
    virtual No** getAdjacentes();
    virtual int getQuantidadeDeAdjacentes();

    virtual void setPadrao(No* padrao, int atraso);
    
    virtual No* getProximoSalto(int endereco, int& atraso);

    virtual void imprimir();
};

#endif
