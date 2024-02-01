#include <iostream>

// Faca os includes necessarios

using namespace std;

class Musica {
public: //Tudo que estiver abaixo dessa linha pode ser acessa em qualquer situação
    string nome;
    int duracao;
    int quantidadeDeAvaliacoes = 0;
    int somaDasAvaliacoes = 0;

    void avaliar(int valor);
    double getMedia();

    void imprimir();
};

/** Implementar metodos da classe Musica **/

void Musica::avaliar(int valor){
    this->quantidadeDeAvaliacoes++;
    this->somaDasAvaliacoes += valor;
}

double Musica::getMedia(){
    double resp = ( (double)somaDasAvaliacoes )/(quantidadeDeAvaliacoes);
    return resp;
}

void Musica::imprimir(){
    cout << this->nome << " - " << this->duracao << " segundos - " << this->getMedia() << endl;
}

class Playlist {
public:
    string nome;
    Musica* m1 = NULL;
    Musica* m2 = NULL;

    int getDuracao();
    bool adicionar(Musica* m);
};

/** Implementar metodos da classe Playlist **/

int Playlist::getDuracao(){
    int resp = 0;

    if(this->m1 != NULL) resp += this->m1->duracao;
    if(this->m2 != NULL) resp += this->m2->duracao;

    return resp;
}

bool Playlist::adicionar(Musica* m){
    if(this->m1 == NULL) {
        this->m1 = m;
        return true;
    } else if (this->m2 == NULL && this->m1 != m) {
        this->m2 = m;
        return true;
    } else return false;
}

/** Implementar a funcao teste **/
void teste() {
    // IMPLEMENTE seguindo o enunciado

    Musica* m1 = new Musica;
    m1->nome = "Roses";
    m1->duracao = 180;

    m1->avaliar(5);
    m1->avaliar(4);
    m1->avaliar(4);

    Musica* m2 = new Musica;
    m2->nome = "Roda-Viva";
    m2->duracao = 233;

    m2->avaliar(5);
    m2->avaliar(3);
    m2->avaliar(1);

    Playlist* p = new Playlist;

    p->adicionar(m1);
    p->adicionar(m2);

    m1->imprimir();
    m2->imprimir();
    cout << p->getDuracao() << endl;
}


/* COMENTE a funcao main() ANTES DE ENVIAR AO JUDGE!
int main() {
    teste();
    return 0;
} */


