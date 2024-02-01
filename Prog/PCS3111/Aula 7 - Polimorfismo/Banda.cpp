#include <algorithm>
#include <iostream>

#include "Banda.h"

Banda::Banda(int quantidadeMaxima, string nome)
    : Artista(quantidadeMaxima, nome), artistas(new Artista*[quantidadeMaxima]) {}

Banda::~Banda() {
}

bool Banda::adicionar(Artista *a) {
    if (quantidadeDeArtistas >= getQuantidadeMaxima())
        return false;

    for (int i = 0; i < quantidadeDeArtistas; i++)
        if (artistas[i] == a)
            return false;

    artistas[quantidadeDeArtistas++] = a;
    return true;
}

double Banda::getNota(){
    double soma = 0;

    for(int i=0; i<quantidadeDeArtistas; i++){
        soma += artistas[i]->getNota();
    }

    double nota = soma/quantidadeDeArtistas;
    nota++;

    if (nota > 5) nota = 5;

    return nota;
}

void Banda::imprimir(){
    cout << "Banda de " << quantidadeDeArtistas << " membros";
    Artista::imprimir();
}
