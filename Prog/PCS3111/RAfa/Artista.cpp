#include <iostream>
#include <stdexcept>
#include "Artista.h"

Artista::Artista(int quantidadeMaxima, string nome)
    : quantidadeMaxima(quantidadeMaxima), nome(nome),
      musicas(new Musica*[quantidadeMaxima]), quantidadeDeMusicas(0) {
    if (quantidadeMaxima <= 1)
        throw new invalid_argument("Quantidade Com Tamanho Invalido");
    if (nome.empty())
        throw new invalid_argument("Artista Com Nome Vazio");
}

Artista::~Artista() {
    cout << "Artista com " << getQuantidadeDeMusicas() << " musica(s) destruido" << endl;

    delete[] musicas;
}

Musica** Artista::getMusicas() {
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

double Artista::getNota() const {
    double soma = 0;
    for (int i = 0; i < quantidadeDeMusicas; i++)
        soma += musicas[i]->getMedia();

    return soma / quantidadeDeMusicas;
}

void Artista::adicionarMusica(Musica* musica) {
    if (quantidadeDeMusicas >= quantidadeMaxima)
        throw new overflow_error("Quantidade maxima de musicas excedido!");

    if (musica == nullptr)
        throw new invalid_argument("Ponteiro de Musica invalido!");

    if (temMusica(musica))
        throw new invalid_argument("Musica repetida adicionada ao Artista!");

    musicas[quantidadeDeMusicas++] = musica;
}

void Artista::imprimir() {
    cout << "Artista " << getNome() << " - nota " << getNota() << endl;
    for (int i = 0; i < quantidadeDeMusicas; i++) {
        cout << "\t";
        musicas[i]->imprimir();
    }
}

bool Artista::temMusica(Musica *m) const {
    for (int i = 0; i < quantidadeDeMusicas; i++)
        if (musicas[i] == m)
            return true;

    return false;
}
