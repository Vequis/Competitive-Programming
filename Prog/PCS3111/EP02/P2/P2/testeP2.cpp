#include <iostream>
using namespace std;

#include "Vacina.h"
#include "Coronavac.h"
#include "Jansen.h"
#include "Passaporte.h"
#include "Cadastro.h"

void testeP2() {
    
    // Crie, nesta ordem as seguintes vacinas:
    // 2 vacinas da Coronavac no dia 20, e mais uma no dia 200
    // 1 vacinas da Jansen no dia 30, e mais uma no dia 300
    Vacina* vacinas[5];
    vacinas[0] = new Coronavac(20);
    vacinas[1] = new Coronavac(20);
    vacinas[2] = new Coronavac(200);
    vacinas[3] = new Jansen(30);
    vacinas[4] = new Jansen(300);

    cout << "Criando vacinas" << endl;



    // Crie 2 passaportes: Judite e Ariel
    Passaporte* p1 = new Passaporte("Judite");
    Passaporte* p2 = new Passaporte("Ariel");

    cout << "Criando passaportes" << endl;



    // Crie um cadastro de nome "Posto USP" e adicione a ele os 2 passaportes
    Cadastro* c = new Cadastro("Posto USP");
    c->adicionarPassaporte(p1);
    c->adicionarPassaporte(p2);

    cout << "Criando cadastro e adicionando passaportes" << endl;



    // Aplique as vacinas corretamente no modo abaixo:

    // Judite: Coronavac, fabricada no dia 20, 1a. dose no dia 10.
    // Ariel:  Jansen, fabricada no dia 30, no dia 40.
    p1->aplicaVacina(vacinas[0], 10);
    p2->aplicaVacina(vacinas[3], 40);

    cout << "Aplicando vacinas" << endl;



    // Imprima o cadastro
    c->imprimir();


    // Tente aplicar a segunda dose de Coronavac (produzida no dia 20) em Judite no dia 350
    // Imprima em uma linha separada a mensagem referente ao tratamento da excecao
    try {
        p1->aplicaVacina(vacinas[1], 350);
    }
    catch (exception* i) {
        cout << i->what() << endl;
        delete i;
    }


    // Aplique em Judite no dia 350 a dose de Coronavac produzida no dia 200
    try {
        p1->aplicaVacina(vacinas[2], 350);
    }
    catch (exception* e) {
        cout << e->what() << endl;
        delete e;
    }


    // Tente agora aplicar em Ariel no dia 400 uma segunda dose de Jansen produzida no dia 300
    // Imprima em uma linha separada a mensagem referente ao tratamento da excecao
    try {
        p2->aplicaVacina(vacinas[4], 300);
    }
    catch (exception* e) {
        cout << e->what() << endl;
        delete e;
    }


    // Imprima o cadastro
    c->imprimir();


    // Destrua o cadastro
    delete c;
  }
