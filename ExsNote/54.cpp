#include <iostream>

using namespace std;

int main() {
    int c;
    cin >> c;
    int tacos[1000001];
    int tacosFabricados = 0;

    for(int i=0;i<=1000000;i++) tacos[i]=0;

    for (int i=0;i<c;i++){
        int leitura;
        cin >> leitura;
        if (tacos[leitura]==0) {
            tacos[leitura]++;
            tacosFabricados++;
        }else tacos[leitura]--;
    }

    cout << tacosFabricados << endl;
    return 0;
}
