#include <iostream>

#include "Artista.h"

Artista::Artista(int quantidadeMaxima, string nome)
    : quantidadeMaxima(quantidadeMaxima), nome(nome),
      musicas(new Musica*[quantidadeMaxima]), quantidadeDeMusicas(0) {}

Artista::~Artista() {
    cout << "Artista com " << getQuantidadeDeMusicas() << " musica(s) destruido" << endl;

    delete[] musicas;
}

Musica** Artista::getMusicas() const {
    return musicas;
}

int Artista::getQuantidadeDeMusicas() const {
    return quantidadeDeMusicas;
}

int Artista::getQuantidadeMaxima() const {
    return quantidadeMaxima;
}

string Artista::getNome() const {
    return nome;
}

double Artista::getNota() {
    double soma = 0;
    for (int i = 0; i < quantidadeDeMusicas; i++)
        soma += musicas[i]->getMedia();

    return soma / quantidadeDeMusicas;
}

bool Artista::adicionarMusica(Musica* musica) {
    if (quantidadeDeMusicas >= quantidadeMaxima)
        return false;

    musicas[quantidadeDeMusicas++] = musica;
    return true;
}

void Artista::imprimir() {
    cout << "- " << getNome() << endl;
    for (int i = 0; i < quantidadeDeMusicas; i++) {
        cout << "\t";
        musicas[i]->imprimir();
    }
}
