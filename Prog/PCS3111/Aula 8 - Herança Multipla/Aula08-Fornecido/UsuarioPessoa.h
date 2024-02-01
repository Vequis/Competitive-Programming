#ifndef USUARIOPESSOA_H
#define USUARIOPESSOA_H

#include <string>
#include "Pessoa.h"
#include "Usuario.h"

using namespace std;

class UsuarioPessoa: public Pessoa, public Usuario {
private:
    string nome, login;
    int maximoFavoritos;
    int quantidadeMaxima;
public:
    UsuarioPessoa(string nome, string login, int maximoFavoritos, int quantidadeMaxima);
    ~UsuarioPessoa();
};

#endif // USUARIOPESSOA_H
