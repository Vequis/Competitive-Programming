#ifndef BANDA_H
#define BANDA_H

#include <string>
#include "Artista.h"

class Banda: public Artista{
private:
    int numeroDeMembros;

public:
    Banda(int numeroDeMembros, int quantidadeMaxima, string nome);
    ~Banda();

    int getNumeroDeMembros();

    void imprimir();
};

#endif // BANDA_H
