#ifndef ROTEADOR_H
#define ROTEADOR_H

#define TAMANHO 10

#include "TabelaDeRepasse.h"
#include "Evento.h"
#include "Fila.h"
#include "Datagrama.h"

class TabelaDeRepasse;
class Evento;

class Roteador{
private:
    int endereco;
    TabelaDeRepasse *tabela;
    Fila *fila;
public:
    Roteador(int endereco);
    ~Roteador();

    bool mapear(int endereco, Roteador* adjacente, int atraso);
    void setPadrao(Roteador* padrao, int atraso);

    int getEndereco();
    void receber(Datagrama* d);
    Evento* processar(int instante);

    void imprimir();
};

#endif