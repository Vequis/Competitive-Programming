#include <iostream>

using namespace std;

int main(){

    int n;
    cin >> n;

    int vetor[n];

    for (int i=0; i<n; i++) cin >> vetor[i];

    int cont = 0;
    int acessos = 0;
    while (n>0 and acessos < 1000000){
        acessos+= vetor[cont];
        cont++;
        n--;
    }

    cout << cont << endl;
    return 0;

}