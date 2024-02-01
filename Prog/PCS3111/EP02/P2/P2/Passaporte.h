#ifndef PASSAPORTE_H
#define PASSAPORTE_H

#include <string>
#include "Vacina.h"

using namespace std;

// NAO ALTERE
#define MAXIMO_VACINAS 3

class Passaporte{
public:
    Passaporte(string nome);
    virtual ~Passaporte();
    virtual string getNome();
    virtual bool aplicaVacina(Vacina* v, int dataAplicacao);
    virtual Vacina** getVacinas();
    virtual int* getDataAplicacoes();
    virtual int getQuantidadeVacinas();
    virtual void imprimir();
private:
    string nome;

    int qtdeVacinas;

    Vacina** vacinas;
    int* aplicacoes;

    void troca(int i, int j);
};

#endif // PASSAPORTE_H
