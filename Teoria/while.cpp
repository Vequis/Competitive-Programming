#include <iostream> // cin e cout

using namespace std;

int main(){

  //Declaro as vari�veis A e B
  int A;
  int B;

  // Leio os valores de A e B
  cin >> A >> B;

  int i = A; //Crio uma vari�vel contador i e digo que ela come�a de A
  while(i<=B){ //Enquanto i for menor ou igual ao B
    if(i%2==0){ //Se i � par
      cout<<i<<" "; //Imprimo o i na tela
    }
    i = i + 1; //Vou para o pr�ximo valor de i
  }

  cout<<"\n"; //Apenas uma quebra de linha.

  return 0;
}
