#ifndef USUARIO_H
#define USUARIO_H
// Inclua aqui as diretivas de compilacao necessarias

#include "Artista.h"
#include <string>

class Usuario{
private:
    int qtdFavoritos;
    int maximoFavoritos;
    Artista** favoritos;
    string login;
public:
    Usuario(string login, int maximoFavoritos);
    ~Usuario();

    string getLogin();
    bool adicionar(Artista* favorito);
    Artista** getFavoritos();
    int getQuantidadeDeFavoritos();

    void imprimir();
};

#endif // USUARIO_H
