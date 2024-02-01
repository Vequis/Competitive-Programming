/*
* Escola Politécnica da Universidade de São Paulo
* EP 01 - PCS3111
* 
* 07/12/2021
* Autores
*   Vítor Eduardo Costa Santos (12551773)
*   Will (Trancou a matrícula)
*/



#include <iostream>
#include "Segmento.h"
#include "Datagrama.h"
#include "TabelaDeRepasse.h"
#include "Evento.h"
#include "Roteador.h"
#include "Rede.h"
#include "Agendador.h"
#include "Chat.h"
#include "PersistenciaDeRede.h"
#include <string>
#include <stdexcept>



using namespace std;

Rede* redeGlobal;
Agendador* agGlobal;
bool fim = false;

void testeSegmento() {
    Segmento* s = new Segmento(1, 2, "Ola");

    s->imprimir();
}

void testeDatagrama() {
    Segmento* s = new Segmento(1, 2, "Ola");

    s->imprimir();

    Datagrama* d = new Datagrama(3, 4, s);

    d->imprimir();
    
}

void carregarRede(string nome) {
    PersistenciaDeRede* pdr = new PersistenciaDeRede(nome);
    redeGlobal = pdr->carregar();
    delete pdr;
}

void TelaInicial() {
    string nome;
    int instanteInicial;
    cout << "Nome do arquivo: ";
    cin >> nome;
    
    cout << "Instante inicial: ";
    cin >> instanteInicial;

    carregarRede(nome);

    agGlobal = new Agendador(instanteInicial, redeGlobal, 10);
    
    cout << endl;
}

void chatDosHospedeiros() {
    list<Hospedeiro*>* hospedeiros = redeGlobal->getHospedeiros();
    list<Hospedeiro*>::iterator it;

    for (it = hospedeiros->begin(); it != hospedeiros->end(); ++it) {
        cout << "Hospedeiro: " << (*it)->getEndereco() << endl;
        vector<Chat*>* chats = (*it)->getChats();

        for (int j = 0; j < (int)chats->size(); ++j) {
            cout << "\tChat: " << chats->at(j)->getPorta() << endl;
        }
    }
}

void TelaSimuladorDeRede() {
    cout << "Simulador de Rede"      << endl;
    cout << "1) Enviar uma mensagem" << endl;
    cout << "2) Passar tempo"        << endl;
    cout << "0) Sair"                << endl;
    cout << "Escolha uma opcao: "           ;

    int opcao;
    cin >> opcao;
    cout << endl;

    if (opcao == 1) {
        chatDosHospedeiros();

        int endereco, porta;
        cout << "Endereco do hospedeiro: ";
        cin >> endereco;
        cout << "Porta do chat: ";
        cin >> porta;

        Hospedeiro* h = dynamic_cast<Hospedeiro*>(redeGlobal->getNo(endereco));

        if (h == NULL) {
            cout << "Erro: Origem Desconhecida" << endl;
            return;
        } else if (h->getChat(porta) == NULL) {
            cout << "Erro: Origem Desconhecida" << endl;
            return;
        }

        Chat* c = h->getChat(porta);

        cout << "Conteudo: " << endl;
        cout << c->getTextoCompleto();
        cout << endl;
        cout << "Mensagem: ";
        
        string texto;
        cin >> texto;
        cout << endl;

        c->enviar(texto);
    
    } else if (opcao == 2) {

        cout << "Quantidade de Tempo: ";

        int tempo;
        cin >> tempo;
        cout << endl;

        for (int i = 1; i <= tempo; ++i) {
            cout << "Instante " << agGlobal->getInstante() << endl;
            cout << "---" << endl;
            agGlobal->processar();
            cout << endl;
        }

    } else {
        fim = true;
    }
}

int main() {
    try {
        TelaInicial();

        while (!fim) {
            TelaSimuladorDeRede();
        }

    } catch (exception* i) {
        cout << "Erro: " << i->what() << endl;
        delete i;
    }

    return 0;
    
}
