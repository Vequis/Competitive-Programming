#include "Banda.h"

#include <string>
#include <iostream>

using namespace std;

Banda::Banda(int numeroDeMembros, int quantidadeMaxima, string nome) :
numeroDeMembros(numeroDeMembros), Artista(quantidadeMaxima, nome){
}

Banda::~Banda(){
    cout << "Banda com " << this->getNumeroDeMembros() << " membros destruida"<< endl;
}

int Banda::getNumeroDeMembros(){
    return this->numeroDeMembros;
}

void Banda::imprimir(){
    cout << this->getNome() << " - " << getNumeroDeMembros() << " membros" << endl;
}

