#include<string>
#include<iostream>
#include "Banda.h"
#include "Usuario.h"

void teste() {
    Artista *a1 = new Artista(2, "Elis Regina");

    a1->adicionarMusica(new Musica(162, "Tiro ao alvaro"));
    a1->adicionarMusica(new Musica(162, "Triste"));

    Banda *b = new Banda(20, 5, "Snarky Puppy");

    b->adicionarMusica(new Musica(645, "Lingus"));
    b->adicionarMusica(new Musica(343, "Tio Macaco"));

    Usuario *u = new Usuario("Mae", 2);

    u->adicionar(a1);
    u->adicionar(b);

    u->imprimir();

    delete u;
    delete a1;
    delete b;
}

/*
int main() {
    teste();
    return 0;
}
*/

