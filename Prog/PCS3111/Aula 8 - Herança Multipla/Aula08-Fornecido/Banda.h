#ifndef BANDA_H
#define  BANDA_H

#include <string>

#include "Artista.h"
#include "Pessoa.h"

using namespace std;

class Banda: public Artista {
private:
    int quantidadeDeArtistas = 0;
    Pessoa** artistas;
    static double bonus;
public:
    Banda(int quantidadeMaxima, string nome);
    virtual ~Banda();

    bool adicionar(Pessoa *a);

    Pessoa** getParticipantes();
    double getNota();
    void imprimir();

    static double getBonus();

    static void setBonus(double valor);
};

#endif /* BANDA_H */
