#include <iostream>

using namespace std;

class Lampada {
public:
    bool acesa = false;
    void ligar();
    void desligar();
    void imprimir();
};

void Lampada::ligar(){
    acesa = true;
}

void Lampada::desligar(){
    acesa = false;
}

void Lampada::imprimir(){
    cout << this->acesa << endl;
}

int main(){
    Lampada *l1 = new Lampada;
    l1->ligar();
    l1->desligar();

    l1->imprimir();

    l1->ligar();

    l1->imprimir();

    return 0;
}
