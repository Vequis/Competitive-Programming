#include <iostream>

using namespace std;

int main() {
    for(int i = 1; i <= n;i++){ // para cada n�mero a ser impresso

  menor = INF; // fazemos menor come�ar como infinito, ou seja, um n�mero muito grande

  for(int j = 1;j <=n;j++){ // percorro o vetor

    if(lista[j] == 0 and vetor[j] < menor){ // procurando um n�mero menor que "menor" que n�o esteja na lista

      menor = vetor[j]; // fa�o "menor" receber seu valor
      ind_menor = j; // e guardo seu �ndice em "ind_menor"
    }
  }

  cout << menor << " "; // imprimo o menor n�mero que achei

  lista[ind_menor]=1; // e guardo seu �ndice na lista de impresos
}

}
