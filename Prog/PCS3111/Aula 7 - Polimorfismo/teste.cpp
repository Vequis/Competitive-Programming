#include <iostream>
#include <string>

#include "Musica.h"
#include "Artista.h"
#include "Playlist.h"

void teste() {

    Playlist *p1 = new Playlist("Favoritos", 2);

    Artista *a1 = new Artista(2, "Tom Jobim");

    Musica *m1 = new Musica(214, "Aguas de marco");

    a1->adicionarMusica(m1);
    p1->adicionar(m1);

    a1->adicionarMusica(new Musica(180, "Samba de uma nota so"));

    p1->adicionar(a1);

    p1->imprimir();
}

/*
int main() {
    teste();
    return 0;
}
*/

