#include <iostream>
#include <algorithm>

using namespace std;

int main(){

    int n;
    cin >> n;

    int vetor[3];
    for (int i=0; i<3; i++){
        cin >> vetor[i];
    }

    sort(vetor, vetor+3);

    int cont =0 ;
    while (vetor[cont] <= n and cont<=2){
        n-=vetor[cont];
        cont++;
    }

    cout << cont << endl;
    return 0;

}