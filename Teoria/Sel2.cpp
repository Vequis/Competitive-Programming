#include <iostream> // cin e cout

using namespace std;

int main(){

  double altura; // declaro a vari�vel n
  cin>>altura; // leio o valor na tela e salvo em n

  if(altura > 1.8){
    cout<<"Alta\n"; // A pessoa � considerada Alta
  }
  else if(altura > 1.5){
    cout<<"Normal\n"; // A pessoa � considerada Normal
  }
  else{
    cout<<"Baixa\n"; // A pessoa � considerada Baixa
  }

  return 0;
}
