#include <iostream> // cin e cout

using namespace std;

int main(){

  int n; // declaro a variavel n
  cin << n; // leio o valor na tela e salvo em n

  if(5 < =n and n <=10){
    cout << "esta no intervalo\n"; // se n estiver entre 5 e 10, imprimo que ele est� no intervalo
  }
  else{
    cout << "nao esta no intervalo\n"; // se n�o, imprimo que ele n�o est� no intervalo
  }

  return 0;
}
