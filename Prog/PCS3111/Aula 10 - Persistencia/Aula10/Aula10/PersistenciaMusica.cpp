#include <stdexcept>
#include <fstream>

#include "PersistenciaMusica.h"

using namespace std;

PersistenciaMusica::PersistenciaMusica(string arquivo) {
    this->arquivo = arquivo;
}

PersistenciaMusica::~PersistenciaMusica() {
    
}

void PersistenciaMusica::inserir(Musica* m) {
    ofstream output;

    output.open(arquivo, ios_base::app);

    output << m->getNome() << endl
        << m->getDuracao() << endl
        << m->getQuantidadeAvaliacoes() << endl
        << m->getSomaDasAvaliacoes() << endl;

    output.close();
}

Musica** PersistenciaMusica::obter(int& quantidade) {
    Musica** musicas = new Musica*[10];
    quantidade = 0;

    ifstream entrada;

    entrada.open(arquivo);

    if (entrada.fail()) {
        entrada.close();
        throw new invalid_argument("Erro de leitura");
    }

    quantidade = 0;

    while (entrada) {
        string nome;
        int duracao, qtdeAvaliacoes, somaAvaliacoes;
        entrada >> nome;

        if (!entrada.eof()) {

            entrada >> duracao >> qtdeAvaliacoes >> somaAvaliacoes;

            Musica* m = new Musica(duracao, nome, qtdeAvaliacoes, somaAvaliacoes);
        
            musicas[quantidade] = m;
            quantidade++;
        }
    }

    if (!entrada.eof()) {
        entrada.close();
        throw new logic_error("Arquivo com formatacao inesperada");
    }

    if (quantidade == 0) {
        entrada.close();
        return NULL;
    }

    entrada.close();
    return musicas;
}

