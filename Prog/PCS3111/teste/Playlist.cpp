#include "Playlist.h"
#include "Musica.h"
#include <string>
#include <iostream>

using namespace std;

int Playlist::getDuracaoTotal(){
    if(quantidade == 0) return -1;

    int duracaoTotal = 0;

    for(int i=0; i<quantidade; i++){
        duracaoTotal += musicas[i]->getDuracao();
    }

    return duracaoTotal;
}

bool Playlist::adicionar(Musica* m){
    if(quantidade == NUMERO_MAXIMO_VALORES){
        return false;
    }

    musicas[quantidade] = m;
    quantidade++;

    return true;
}

void Playlist::setNome(string nome){
    this->nome = nome;
}

string Playlist::getNome(){
    return nome;
}

int Playlist::getQuantidade(){
    return quantidade;
}

void Playlist::imprimir(){
    cout << getNome() << " - " << getDuracaoTotal() << "segundos no total" << endl;

    for(int i=0; i<quantidade; i++){
        musicas[i]->imprimir();
    }
}
