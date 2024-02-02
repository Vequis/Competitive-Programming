#include <iostream>

using namespace std;

int main() {
    int n,matriz[50][50];
    cin >> n;

    //Lendo qtde cenouras em cada célula;
    for (int i=0;i<n;i++){
        for (int j=0;j<n;j++){
            cin>>matriz[i][j];
        }
    }

    int q;
    cin >> q;
    int linicial,lfinal,cinicial,cfinal;
    int qtdCen = 0;

    for (int k=0;k<q;k++){
    cin >> linicial >> cinicial >> lfinal >> cfinal;
        for (int i=linicial-1;i<lfinal;i++){
            for (int j=cinicial-1;j<cfinal;j++) {
                qtdCen += matriz[i][j];
                matriz[i][j] = 0;
            }
        }
    }

    cout << qtdCen << endl;
    return 0;
}
