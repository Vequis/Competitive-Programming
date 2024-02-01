#include "Usuario.h"
#include <iostream>

using namespace std;

Usuario::Usuario(string login, int maximoFavoritos) : login(login), maximoFavoritos(maximoFavoritos) {
    favoritos = new Artista*[maximoFavoritos];
    qtdFavoritos = 0;
}

Usuario::~Usuario(){
    delete[] favoritos;
}

string Usuario::getLogin(){
    return this->login;
}

Artista** Usuario::getFavoritos(){
    return this->favoritos;
}

int Usuario::getQuantidadeDeFavoritos(){
    return this->qtdFavoritos;
}

bool Usuario::adicionar(Artista *favorito){
    if(qtdFavoritos == maximoFavoritos) return false;

    for(int i=0; i<qtdFavoritos; i++){
        if (favorito == favoritos[i]) return false;
    }

    favoritos[qtdFavoritos] = favorito;
    qtdFavoritos++;
}

void Usuario::imprimir() {
  cout << "Usuario(a) " << this->getLogin()  << " com " << this->getQuantidadeDeFavoritos() << " favoritos:" << endl;
  for (int i = 0; i < this->getQuantidadeDeFavoritos(); i++) {
    cout << "Favorito " << i + 1 << ": ";
    this->getFavoritos()[i]->imprimir();
    cout << "\n";
  }
}
