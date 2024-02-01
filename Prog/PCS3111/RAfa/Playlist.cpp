#include <iostream>
#include <stdexcept>


#include "Playlist.h"

using namespace std;

Playlist::Playlist(string nome) : nome(nome) {
    if (nome.empty())
        throw new invalid_argument("Playlist Com Nome Vazio");
    musicas = new vector<Musica*>();
}

Playlist::~Playlist() {
    delete musicas;
}

string Playlist::getNome() {
    return nome;
}

int Playlist::getDuracao() {
    int duracao = 0;
    for (unsigned int i = 0; i < musicas->size(); i++)
        duracao += musicas->at(i)->getDuracao();

    return duracao;
}

vector<Musica*>* Playlist::getMusicas() {
    return musicas;
}

void Playlist::adicionar(Musica *m) {
    if (m == nullptr)
        throw new invalid_argument("Ponteiro de Musica invalido!");

    if (temMusica(m))
        throw new invalid_argument("Musica repetida adicionada à Playlist!");

    musicas->push_back(m);
}

double Playlist::getAvaliacaoDasMusicas() const {
    double soma = 0;
    int numeroMusicas = 0;
    for (unsigned int i = 0; i < musicas->size(); i++) {
        try {
            soma += musicas->at(i)->getMedia();
            numeroMusicas++;
        } catch (invalid_argument*) {}
    }

    return soma / numeroMusicas;
}

void Playlist::imprimir() {
    cout << "Playlist " << nome << " - duracao " << getDuracao() << " - media " << getAvaliacaoDasMusicas() << endl;
    for (unsigned int i = 0; i < musicas->size(); i++) {
        cout << "\t";
        (*musicas)[i]->imprimir();
    }
}

bool Playlist::temMusica(Musica *m) const {
    for (unsigned int i = 0; i < musicas->size(); i++)
        if ((*musicas)[i] == m)
            return true;

    return false;
}
