#include <iostream>
#include <string>
#include "Musica.h"

using namespace std;

string Musica::getNome(){
    return nome;
}

void Musica::setNome(string nome){
    this->nome = nome;
}

int Musica::getDuracao(){
    return duracao;
}

void Musica::setDuracao(int duracao){
    this->duracao = duracao;
}

void Musica::avaliar(int nota) {
    somaDasAvaliacoes += nota;
    quantidadeDeAvalicoes++;
}

double Musica::getMedia() {
    return ((double)somaDasAvaliacoes)/quantidadeDeAvalicoes;
}

void Musica::imprimir() {
    cout << nome << " - " << duracao << " segundos - " << this->getMedia()  << " avaliacao" << endl;
}
