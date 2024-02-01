#ifndef ROTEADOR_H
#define ROTEADOR_H

#include "No.h"
#include "TabelaDeRepasse.h"
#include "Evento.h"
#include "Fila.h"
#include "Datagrama.h"

class Roteador : public No {
public:
    Roteador(int endereco);
    virtual ~Roteador();

    virtual void mapear(int endereco, No* adjacente, int atraso);
    virtual void setPadrao(No* padrao, int atraso);
    
    static const int TAMANHO_TABELA = 10;
    
    //Redefinicoes
    virtual Evento* processar(int instante);
    virtual void imprimir();

protected: 
    Roteador(int endereco, Fila* fila);
    TabelaDeRepasse* tabela;
};

#endif