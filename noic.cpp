#include <iostream>
#include <cmath>
#include <vector>
#include <algorithm>

using namespace std;


int main() {
    int n;
    cin >> n;

    int vetor[100100];

    int soma = 0;
    for (int i=0; i<n; i++){
        int num;
        cin >> num;

        vetor[i] = num;
    }

    sort(vetor, vetor+n);

    int ptin = 0;

    int cont = 0;
    for (int i=n-1; i>=ptin; i--){
        int soma = vetor[i];

        while (soma+vetor[ptin]<=4){
            ptin++;
            soma += vetor[ptin];
        }

        cont++;
    }

    cout << cont << endl;
}
