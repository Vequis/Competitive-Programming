#include <iostream>
#include "Musica.h"
#include "Artista.h"
#include <string>

using namespace std;

void teste() {
    Musica *m1 = new Musica(162, "Tiro ao alvaro");
    Musica *m2 = new Musica(162, "Triste");
    Musica *m3 = new Musica(214, "Aguas de marco");
    Musica *m4 = new Musica(228, "Bala com bala");

    Artista *a = new Artista(23, "Elis Regina");

    a->adicionarMusica(m1);
    a->adicionarMusica(m2);
    a->adicionarMusica(m3);
    a->adicionarMusica(m4);

    delete a;
}

/*
int main() {
    teste();
    return 0;
}
*/

