#include <iostream>
#include <stdexcept>
#include "Artista.h"

Artista::Artista(string nome) : nome(nome),
      musicas(new list<Musica*>()){
}

Artista::~Artista() {
    cout << "Artista com " << musicas->size() << " musica(s) destruido" << endl;

    delete musicas;
}

list<Musica*>* Artista::getMusicas() {
    return musicas;
}


string Artista::getNome() const {
    return nome;
}

double Artista::getNota() const {
    double soma = 0;
    list<Musica*>::iterator it;
    for (it = musicas->begin(); it != musicas->end(); it++)
        soma += (*it)->getMedia();

    return soma / musicas->size();
}

void Artista::adicionarMusica(Musica* musica) {

    if (musica == nullptr)
        throw new invalid_argument("Ponteiro de Musica invalido!");

    if (temMusica(musica))
        throw new invalid_argument("Musica repetida adicionada ao Artista!");

    musicas->push_back(musica);
}

void Artista::imprimir() {
    cout << "Artista " << getNome() << " - nota " << getNota() << endl;
    list<Musica*>::iterator it;
    for (it = musicas->begin(); it != musicas->end(); it++) {
        cout << "\t";
        (*it)->imprimir();
    }
}

bool Artista::temMusica(Musica *m) const {
    list<Musica*>::iterator it;
    for (it = musicas->begin(); it != musicas->end(); it++)
        if ((*it) == m)
            return true;

    return false;
}
