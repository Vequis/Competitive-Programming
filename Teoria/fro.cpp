#include <iostream> // cin e cout

using namespace std;

int main(){

    int var;

    for(int i=1;i<=10;i++){ // Repete uma sequência de comandos 10 vezes
        cin>>var; //Ler um valor e armazena em var

        if(var == 0){//Se o valor for igual a 0
            break; //Encerre o for
        }

        cout<<2*var<<"\n";
    }

    return 0;
}
