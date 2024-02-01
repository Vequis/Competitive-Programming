#ifndef PLAYLIST_H
#define PLAYLIST_H

#define NUMERO_MAXIMO_VALORES 10
#include <string>
#include "Musica.h"

using namespace std;

class Playlist {
private:
    string nome;
    Musica *musicas[NUMERO_MAXIMO_VALORES];
    int quantidade = 0;
public:
    int getDuracaoTotal();
    bool adicionar(Musica* m);

    void setNome(string nome);
    string getNome();
    int getQuantidade();

    void imprimir();
};

#endif
