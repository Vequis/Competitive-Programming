#include <iostream>
#include <string> 

using namespace std;

//IMPLEMENTE AS FUNCOES
// EXERCICIO 1
/*
int calcularNota(int numeroDeReproducoes, int quantidadeDePositivos, int quantidadeDeUsuariosQueOuviram) {
    double porcentagem = ((double)quantidadeDePositivos)/quantidadeDeUsuariosQueOuviram;

    if(numeroDeReproducoes >= 1000000){
        return 5;
    } else if (numeroDeReproducoes>=100000 || porcentagem>=0.5){
        return 4;
    } else if (numeroDeReproducoes>=10000 || porcentagem>=0.35){
        return 3;
    } else if (numeroDeReproducoes>=1000 || porcentagem>=0.2){
        return 2;
    } else if (numeroDeReproducoes>=100 || porcentagem>=0.15){
        return 1;
    } else {
        return 0;
    }
}
*/

// EXERCICIO 2
/*
int calcularTempoTotal(int nota, int notas[], int duracoes[], int quantidade) {
    int resultado = 0;

    for(int i=0; i<quantidade; i++){
        if(notas[i] == nota){
            resultado += duracoes[i];
        }
    }

    return resultado;
}
*/

// EXERCICIO 3

bool temRepetido(string artistas[], int quantidade) {
    bool resp = false; //Assumimos, inicialmente que resp é falsa
    
    for(int i=0; i<quantidade; i++){
        for(int j=i+1; j<quantidade; j++){ //Já conferimos para os elementos menores que i
            if(artistas[i] == artistas[j]){
                resp = true; //é true <=> a condição for verdadeira em algum momento
            }
        }
    }

    return resp;

    //Complexidade de tempo : n + (n-1) + ... + 2 + 1 = n*(n+1)/2 => O(n²)

}


// /* COMENTE A MAIN PARA SUBMETER */
// int main() {

//     return 0;
// }
