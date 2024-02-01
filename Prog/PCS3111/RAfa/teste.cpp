#include <iostream>
#include <string>
#include "Musica.h"
#include "Artista.h"
#include "Playlist.h"

using namespace std;

void teste() {
    Playlist* favoritos = new Playlist("Favoritos");

    Artista* tomJobim = new Artista(2, "Tom Jobim");

    Musica* aguasDeMarco = new Musica(214, "Aguas de marco");
    Musica* maisNinguem = new Musica(168, "Mais ninguem");
    Musica* sambaDeUmaNotaSo = new Musica(180, "Samba de uma nota so");

    aguasDeMarco->avaliar(5);
    aguasDeMarco->avaliar(4);
    aguasDeMarco->avaliar(5);

    maisNinguem->avaliar(3);
    maisNinguem->avaliar(3);
    maisNinguem->avaliar(3);

    sambaDeUmaNotaSo->avaliar(5);
    sambaDeUmaNotaSo->avaliar(3);

    tomJobim->adicionarMusica(aguasDeMarco);
    tomJobim->adicionarMusica(sambaDeUmaNotaSo);

    favoritos->adicionar(aguasDeMarco);
    favoritos->adicionar(maisNinguem);

    favoritos->imprimir();
    tomJobim->imprimir();
}
/*
int main() {
    teste();
    return 0;
}
*/
