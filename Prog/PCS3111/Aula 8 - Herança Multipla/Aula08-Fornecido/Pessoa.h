#ifndef PESSOA_H
#define PESSOA_H
#include <string>

#include "Artista.h"

using namespace std;

class Pessoa: public Artista {
private:
    int quantidadeMaxima;
    string nome;
public:
    Pessoa(int quantidadeMaxima, string nome);
    virtual ~Pessoa();

    void imprimir();
};

#endif // PESSOA_H
