#ifndef CADASTRO_H
#define CADASTRO_H

#include <string>
#include <vector>
#include "Passaporte.h"

using namespace std;

class Cadastro {
public:
    Cadastro(string nomePosto);
    virtual ~Cadastro();
    virtual string getNomePosto();
    virtual void adicionarPassaporte(Passaporte* passaporte);
    virtual vector<Passaporte*>* getPassaportes();
    virtual void imprimir();
private:
    string nomePosto;

    vector<Passaporte*>* passaportes;
};

#endif // CADASTRO_H
