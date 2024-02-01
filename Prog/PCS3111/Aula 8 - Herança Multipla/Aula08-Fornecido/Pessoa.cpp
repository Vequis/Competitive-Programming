#include "Pessoa.h"
#include <iostream>

using namespace std;

Pessoa::Pessoa(int quantidadeMaxima, string nome) : Artista(quantidadeMaxima, nome) {
}

Pessoa::~Pessoa() {
}

void Pessoa::imprimir() {
    cout << "- " << this->getNome() << endl;

    Musica** musicas = this->getMusicas();
    for (int i = 0; i < this->getQuantidadeDeMusicas(); i++) {
        cout << "\t";
        musicas[i]->imprimir();
    }
}
