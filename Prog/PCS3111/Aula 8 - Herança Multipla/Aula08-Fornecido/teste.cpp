#include <iostream>
#include "Pessoa.h"
#include "Banda.h"

using namespace std;

void teste() {
    Pessoa* p1 = new Pessoa(1, "Tom Jobim");
    Musica* m1 = new Musica(180, "Samba de uma nota so");
    m1->avaliar(5);

    p1->adicionarMusica(m1);

    Pessoa* p2 = new Pessoa(1, "Elis Regina");
    Musica* m2 = new Musica(214, "Aguas de marco");
    m2->avaliar(4);

    p2->adicionarMusica(m2);

    Banda* b = new Banda(2, "Elis & Tom");
    b->adicionar(p1);
    b->adicionar(p2);

    cout << b->getNota() << endl;
    b->setBonus(0.2);
    cout << b->getNota() << endl;
}


int main() {
    teste();
    return 0;
}



