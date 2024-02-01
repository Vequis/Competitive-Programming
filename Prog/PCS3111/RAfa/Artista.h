#ifndef ARTISTA_H
#define  ARTISTA_H

#include <string>

#include "Musica.h"

using namespace std;

class Artista {
private:
    int quantidadeMaxima;
    string nome;
    Musica** musicas;
    int quantidadeDeMusicas;

    bool temMusica(Musica *m) const;

public:
    Artista(int quantidadeMaxima, string nome);
    virtual ~Artista();

    Musica** getMusicas();
    int getQuantidadeDeMusicas()  const;
    int getQuantidadeMaxima()  const;

    string getNome() const;

    virtual double getNota() const;

    void adicionarMusica(Musica* musica);

    void imprimir();
};

#endif /* ARTISTA_H */
