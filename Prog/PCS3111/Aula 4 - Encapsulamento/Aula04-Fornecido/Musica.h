#ifndef MUSICA_H
#define MUSICA_H

#include <string>

using namespace std;

class Musica {
private:
    string nome;
    int duracao;
    int quantidadeDeAvalicoes = 0;
    int somaDasAvaliacoes = 0;
public:
    string getNome();
    void setNome(string nome);
    int getDuracao();
    void setDuracao(int duracao);

    void avaliar(int nota);
    double getMedia();

    void imprimir();
};

#endif // MUSICA_H
