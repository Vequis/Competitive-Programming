#include <iostream>
#include <string>

using namespace std;

// Use os includes necessarios.
// Exercicio 1
/*
string* encontrarMusica(int duracoes[], string estilos[], string nomes[],
                        int quantidade, string estilo, int duracao) {

    string* resp = NULL;

    for (int i=0; i < quantidade; i++) {
        if(estilos[i] == estilo && duracoes[i] == duracao){
            return &nomes[i];
        }
    }

    return resp; //retorna o valor NULL se não encontra par válido

}
*/

// Exercicio 2
int calcularEstatisticas(int duracoes[], int quantidade, int& minimo,
                         int* maximo) {

    *maximo = 0;
    int soma = 0;

    if (quantidade == 0){
        minimo = 0;
        return 0;
    } else {
        minimo = duracoes[0];
    }

    for(int i = 0; i < quantidade; i++){
        if (duracoes[i] > *maximo) {
            *maximo = duracoes[i];
        }

        if (duracoes[i] < minimo){
            minimo = duracoes[i];
        }

        soma += duracoes[i];
    }

    return soma;
}


////////////////////////////////////////////
// REMOVA A MAIN ANTES DE ENVIAR AO JUDGE //
////////////////////////////////////////////
/*
int main() {
    string nomes[3] = {"Redemption Song", "Alien", "Octavarium"};
    int duracoes[] = {4, 3, 24};
    string estilos[] = {"Reggae", "Alternativa", "Metal"};

    int minimo, maximo;
    cout << calcularEstatisticas(duracoes, 3, minimo, &maximo) << endl;
    cout << minimo << ' ' << maximo << endl;

    return 0;
}
*/
