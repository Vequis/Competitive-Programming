#include <iostream>

using namespace std;

int potencia(int a, int b){
    int resultado = 1;
    int potatual = a;

    while(b>0){
        if(b%2 == 1){
            resultado*=potatual;
        }

        b/=2;
        potatual *= potatual;
    }

    return resultado;
}
