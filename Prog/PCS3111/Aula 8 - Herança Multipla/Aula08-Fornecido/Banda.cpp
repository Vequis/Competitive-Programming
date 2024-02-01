#include <algorithm>
#include <iostream>

#include "Banda.h"

double Banda::bonus = 0.1;

Banda::Banda(int quantidadeMaxima, string nome)
    : Artista(quantidadeMaxima, nome), artistas(new Pessoa*[quantidadeMaxima]) {}

Banda::~Banda(){}

bool Banda::adicionar(Pessoa *a) {
    if (quantidadeDeArtistas >= getQuantidadeMaxima())
        return false;

    for (int i = 0; i < quantidadeDeArtistas; i++)
        if (artistas[i] == a)
            return false;

    artistas[quantidadeDeArtistas++] = a;
    return true;
}

double Banda::getNota() {
    double soma = 0;
    for (int i = 0; i < quantidadeDeArtistas; i++)
        soma += artistas[i]->getNota();

    return min(soma/quantidadeDeArtistas + getBonus(), 5.0);
}

Pessoa** Banda::getParticipantes(){
    return artistas;
}

void Banda::imprimir() {
  cout << "Banda de " << quantidadeDeArtistas << " membros" << endl;
}

double Banda::getBonus() {
    return bonus;
}

void Banda::setBonus(double valor) {
    bonus = valor;
}

