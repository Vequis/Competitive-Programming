#include<bits/stdc++.h>


#define endl '\n'


using namespace std;

class Personagem() {
public:
    string nome;
    int forca;
    int defesa;

    void atacar(Personagem* alvo);
    void defender(int ataque);

};

void Personagem::atacar(Personagem* alvo){
    alvo->defender(5 * this->ataque);
}

void Personagem::defender(int ataque){
    if(ataque > defesa){
        this->vida = this->vida - ataque;
        cout << this->nome << " sofreu  dano" << endl;
    } else {
        cout << "Nem fez cocegas" << endl;
    }
}

int main(){

    Personagem* p1 = new Personagem();
    p1->nome = "Jao";
    p1->forca = 10;
    p1->defesa = 2;

    Personagem* p1 = new Personagem();
    p1->nome = "Cleide";
    p1->forca = 12;
    p1->defesa = 4;

    Personagem* daVez = p1;
    Personagem* alvo = p2;
    while(p1->vida > 0 && p2->vida > 0){
        daVez->atacar(alvo);
        daVez = alvo;

        if(daVez == p1) alvo = p2;
        else alvo = p1;

    }

    cout << "P1: " << P1->nome <<

    return 0;
}
