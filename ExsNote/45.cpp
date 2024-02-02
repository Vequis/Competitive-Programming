#include <iostream>

using namespace std;

int main(){
    int n;
    cin >> n;
    int matriz[n][n];
    int soma,somamax;
    int soma_linhas[n],soma_colunas[n];

    for (int i=0;i<n;i++) {
        soma_linhas[i]=0;
        soma_colunas[i]=0;
    }

    for (int i=0;i<n;i++){
        for (int j=0;j<n;j++){
            cin>>matriz[i][j];
            soma_linhas[i]+=matriz[i][j];
            soma_colunas[j]+=matriz[i][j];
        }
    }

    somamax=0;
    for (int i=0;i<n;i++){
        for (int j=0;j<n;j++){
            soma = soma_linhas[i] + soma_colunas[j] - (2*matriz[i][j]);
            if (soma > somamax) somamax = soma;
        }
    }

    cout << somamax << endl;
    return 0;
}
