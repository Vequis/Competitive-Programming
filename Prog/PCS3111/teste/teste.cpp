#include <iostream>
#include "Musica.h"
#include "Playlist.h"
#include <string>
using namespace std;

void teste() {
    Musica *m1 = new Musica;
    Musica *m2 = new Musica;

    m1->setNome("Roses");
    m1->setDuracao(180);

    m1->avaliar(3);
    m1->avaliar(3);
    m1->avaliar(1);

    m2->setNome("Overdue");
    m2->setDuracao(210);

    m2->avaliar(1);
    m2->avaliar(5);
    m2->avaliar(4);

    Playlist *p1 = new Playlist;

    p1->setNome("Estrangeiras");
    p1->adicionar(m1);
    p1->adicionar(m2);

    p1->imprimir();
}

int main() {
    teste();
    return 0;
}


