#include <iostream>

using namespace std;

int main() {
    for(int i = 1; i <= n;i++){ // para cada número a ser impresso

  menor = INF; // fazemos menor começar como infinito, ou seja, um número muito grande

  for(int j = 1;j <=n;j++){ // percorro o vetor

    if(lista[j] == 0 and vetor[j] < menor){ // procurando um número menor que "menor" que não esteja na lista

      menor = vetor[j]; // faço "menor" receber seu valor
      ind_menor = j; // e guardo seu índice em "ind_menor"
    }
  }

  cout << menor << " "; // imprimo o menor número que achei

  lista[ind_menor]=1; // e guardo seu índice na lista de impresos
}

}
