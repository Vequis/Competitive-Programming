#include "Rede.h"
#include <iostream>

using namespace std;

Rede::Rede() {
    quantidade = 0;
    nos = new list<No*>();
}

Rede::~Rede(){
    for (it = nos->begin(); it != nos->end(); ++it) {
        delete (*it);
    }

    delete nos;
}

void Rede::adicionar(No* n) {

    for (it = nos->begin(); it != nos->end(); ++it) {
        if ((*it)->getEndereco()  == n->getEndereco()) {
            throw new logic_error("Endereco repetido");
        }
    }

    nos->push_back(n);
    quantidade++;
}

No* Rede::getNo(int endereco) {
    for (it = nos->begin(); it != nos->end(); ++it) {
        if ((*it)->getEndereco() == endereco) {
            return (*it);
        }
    }

    return NULL;
}

list<No*>* Rede::getNos() {
    return nos;
}

list<Hospedeiro*>* Rede::getHospedeiros() {
    list<Hospedeiro*>* hospedeiros = new list<Hospedeiro*>();

    for (it = nos->begin(); it != nos->end(); ++it) {
        Hospedeiro* atual = dynamic_cast<Hospedeiro*>((*it));
        
        if (atual != NULL) {
            hospedeiros->push_back(atual);
        }
    }

    return hospedeiros;
}

void Rede::imprimir(){
    cout << "Essa rede tem " << quantidade << " nos" << endl;
}
