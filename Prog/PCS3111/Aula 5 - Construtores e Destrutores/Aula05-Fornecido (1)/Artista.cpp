#include <iostream>
#include <string>
#include "Artista.h"

Artista::Artista(int quantidadeMaxima, string nome):
quantidadeMaxima(quantidadeMaxima), nome(nome) {
    musicas = new Musica*[quantidadeMaxima];
    this->quantidade = 0;

    for(int i=0; i<quantidadeMaxima; i++){
        musicas[i] = new Musica(0, "");
    }
}

Artista::~Artista() {
    cout << "Artista com " << this->quantidade << " musica(s) destruido" << endl;

   for (int i=0; i<quantidade; i++){
        delete musicas[i];
   }

}

Musica** Artista::getMusicas() const {
    return musicas;
}

int Artista::getQuantidadeMusicas() const {
    return quantidade;
}

int Artista::getQuantidadeMaximaMusicas() const {
    return quantidadeMaxima;
}

string Artista::getNome() const {
    return nome;
}

bool Artista::adicionarMusica(Musica* musica) {
    if (quantidade >= quantidadeMaxima)
        return false;

    musicas[quantidade++] = musica;
    return true;
}

void Artista::imprimir() {
    cout << getNome() << endl;
    for(int i = 0; i < quantidade; i++) musicas[i]->imprimir();
}
