#ifndef BANDA_H
#define  BANDA_H

#include <string>

#include "Artista.h"

using namespace std;

class Banda: public Artista {
private:
    Artista** artistas;
    int quantidadeDeArtistas = 0;

public:
    Banda(int quantidadeMaxima, string nome);
    ~Banda();

    bool adicionar(Artista *a);
    double getNota();

    void imprimir();
};

#endif /* BANDA_H */
