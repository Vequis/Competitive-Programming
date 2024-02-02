#include <iostream>

using namespace std;

int matriz[11][11];

int main() {

    int n;
    cin >> n;
    int soma = 0;
    int somaA = 0;
    int somaB = 0;
    int var = 1;

    //Lendo os valores do quadrado mágico
    for (int i=0;i<n;i++){ //linha
        for (int j=0;j<n;j++) { //coluna
            cin>>matriz[i][j];
        }
    }

    for (int i=0;i<n;i++){
        soma+=matriz[0][i];
    }

    for (int i=0;i<n;i++){
        somaA=0;
        somaB=0;
        for (int j=0;j<n;j++) {
            somaA += matriz[i][j];
            somaB += matriz[j][i];
        }
        if ((somaA != soma)or(somaB != soma)) {var = 0;}
    }

    somaA=0;
    somaB=0;
    for (int i=0;i<n;i++){
        somaA+=matriz[i][i];
        somaB+=matriz[i][n-(1+i)];
    }
    if ((somaA != soma)or(somaB != soma)){var=0;}

    if (var==1){cout << soma << endl;
    } else if (var==0) {cout << -1 << endl;}

    return 0;
}
