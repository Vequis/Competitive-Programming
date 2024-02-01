/*
* Escola Politécnica da Universidade de São Paulo
* EP 01 - PCS3111
* 
* 22/10/2021
* Autores
*   Vítor Eduardo Costa Santos (12551773)
*   Will (Trancou a matrícula)
*/



#include <iostream>
#include "Datagrama.h"
#include "TabelaDeRepasse.h"
#include "Evento.h"
#include "Roteador.h"
#include "Rede.h"
#include "Agendador.h"
#include <string>

using namespace std;

Rede *redeGlobal;
Agendador * agendadorGlobal;
bool isOver = false;

Datagrama *atuall;

void telaEnvioDatagrama() {
    int origem, instante, destino;
    string mensagem;

    cout << "Endereco do roteador de origem: ";
    cin >> origem;
    cout << "Instante: ";
    cin >> instante;
    cout << "Endereco de destino: ";
    cin >> destino;
    cout << "Mensagem: ";
    cin >> mensagem;

    if (agendadorGlobal->getQuantidade() == 10) {
        cout << "Erro: Sem espaco para agendar o evento" << endl;
        return;
    }

    Datagrama *DatagramaAtual = new Datagrama(origem, destino, mensagem);
    Roteador **roteadoresRede = redeGlobal->getRoteadores();
    int tamanhoRede = redeGlobal->getQuantidade();

    Roteador *inicial = NULL;

    for (int i = 0; i < tamanhoRede; i++) {
        if (roteadoresRede[i]->getEndereco() == origem) {
            inicial = roteadoresRede[i];
            break;
        }
    }

    if (inicial!= NULL && !agendadorGlobal->agendar(instante, inicial, DatagramaAtual)) {
        cout << "Erro: origem desconhecida" << endl;
    }

    cout << endl;

    delete[] roteadoresRede;
}

void telaPassarTempo() {
    int qtdTempo;
    cout << "Quantidade de tempo: ";
    cin >> qtdTempo;
    cout << endl;

    for(int i = 0; i < qtdTempo; i++) {
        cout << "Instante: " << agendadorGlobal->getInstante() << endl;
        cout << "---" << endl;
        agendadorGlobal->processar();

        cout << endl;
    }

    cout << endl;
}

void inicializarRede() {
    Roteador **r = new Roteador*[7];

    for (int i = 1; i <= 6; i++) {
        r[i] = new Roteador(i);
    }

    r[1]->setPadrao(r[3], 1);
    r[1]->mapear(2, r[2], 2);

    r[2]->setPadrao(r[4], 1);
    r[2]->mapear(1, r[1], 2);

    r[3]->setPadrao(r[4], 1);
    r[3]->mapear(1, r[1], 1);
    r[3]->mapear(5, r[5], 2);

    r[4]->setPadrao(r[3], 1);
    r[4]->mapear(2, r[2], 1);
    r[4]->mapear(6, r[6], 1);

    r[5]->setPadrao(r[3], 2);
    r[5]->mapear(6, r[6], 2);

    r[6]->setPadrao(r[4], 1);
    r[6]->mapear(5, r[5], 2);

    redeGlobal = new Rede(6);

    for(int i = 0; i < 6; i++) {
        redeGlobal->adicionar(r[i+1]);
    }

    delete[] r;
}

void telaInicial() {
    int opcao;

    cout << "Simulador de Rede" << endl;
    cout << "1) Enviar um datagrama" << endl;
    cout << "2) Passar tempo" << endl;
    cout << "0) Sair" << endl;
    cout << "Escolha uma opcao: ";
    cin >> opcao;
    cout << endl;

    if (opcao == 1) {
        telaEnvioDatagrama();
    } else if (opcao == 2) {
        telaPassarTempo();
    } else {
        isOver = true;
    }
}

void testeDatagrama() {
    Datagrama *d = new Datagrama(1, 5, "Ola");

    cout << d->getOrigem() << endl;
    cout << d->getDestino() << endl;
    cout << d->getDado() << endl;

    d->imprimir();

    delete d;
}

void testeFila() {
    Fila *f = new Fila(3);

    Datagrama *d1 = new Datagrama(1, 5, "1");
    Datagrama *d2 = new Datagrama(2, 3, "2");
    Datagrama *d3 = new Datagrama(3, 5, "3");

    f->enqueue(d1);
    f->enqueue(d2);

    Datagrama *d;
    d = f->dequeue();
    d->imprimir();

    d = f->dequeue();
    d->imprimir();

    f->enqueue(d1);
    f->enqueue(d2);
    cout << f->enqueue(d2) << endl;

    cout << f->enqueue(d3) << endl;

    delete d;
    delete f;
}

void testeTabela() {
    TabelaDeRepasse *t = new TabelaDeRepasse(3);

    Roteador *r1 = new Roteador(1);
    Roteador *r2 = new Roteador(2);
    Roteador *r3 = new Roteador(3);
    Roteador *r4 = new Roteador(4);

    t->setPadrao(r1, 3);

    t->mapear(2, r2, 3);
    t->mapear(1, r1, 1);
    t->mapear(4, r3, 2);
    t->mapear(1, r2, 4);
    cout << t->mapear(4, r4, 5) << endl;

    int tamanho_rs = t->getQuantidadeDeAdjacentes();
    Roteador **rs = t->getAdjacentes();

    for (int i = 0; i < tamanho_rs; i++) {
        cout << rs[i]->getEndereco() << endl;
    }

    int atrasoo = 0;
    cout << "Endereco: " << t->getProximoSalto(1, atrasoo)->getEndereco() << endl;
    cout << "Atraso :" << ' ' << atrasoo << endl;

    delete r1;
    delete r2;
    delete r3;
    delete r4;
    delete t;
    delete[] rs;
}

void testeEvento() {
    Datagrama *d1 = new Datagrama(2, 1, "Ola");

    Roteador *r1 = new Roteador(1);

    Evento *e = new Evento(3, r1, d1);

    e->imprimir();

    cout << e->getInstante() << endl;
    cout << e->getDestino()->getEndereco() << endl;
    cout << e->getDatagrama()->getDado() << endl;

    delete d1;
    delete r1;
    delete e;
}

void testeRoteador() {
    Roteador *r1 = new Roteador(1);

    Roteador *r2 = new Roteador(2);
    Roteador *r3 = new Roteador(3);
    Roteador *r4 = new Roteador(4);

    Roteador *r7 = new Roteador(7);

    r1->mapear(2, r2, 1);
    r1->mapear(3, r3, 1);
    r1->mapear(4, r3, 4);

    r1->setPadrao(r7, 6);

    Evento * e = r1->processar(1);
    if ( e == NULL) {
        cout << "Calma, muito cedo!" << endl;
    }

    r1->receber(new Datagrama(1, 2, "Quero ir pra 2!"));
    r1->receber(new Datagrama(1, 3, "Quero ir pra 3!"));
    r1->receber(new Datagrama(1, 4, "Quero ir pra 4!"));
    r1->receber(new Datagrama(1, 1632, "Quero ir pra qualquer lugar!"));

    e = r1->processar(2);
    e = r1->processar(e->getInstante());
    e = r1->processar(e->getInstante());
    e = r1->processar(e->getInstante());

    delete e;
    delete r1, r2, r3, r4, r7;
}

void testeRede(){
    Roteador **vetor = redeGlobal->getRoteadores();

    for (int i = 0; i < redeGlobal->getQuantidade(); i++) {
        cout << vetor[i]->getEndereco() << endl;
    }
}

void testeAgendador(Datagrama *d) {
    //Não se mostrou necessario
}

int main() {
    inicializarRede();

    agendadorGlobal = new Agendador(1, redeGlobal, 10);

    while(!isOver){
        telaInicial();
    }

    delete redeGlobal;
    delete agendadorGlobal;

    return 0;
}
