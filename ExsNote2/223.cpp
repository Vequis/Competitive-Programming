#include <iostream>

using namespace std;

int main(){
    int b, n;
    int fundo[21];

    while(true){
        cin >> b >> n;

        if (b==0 && n==0){
            break;
        }

        for (int i=1;i<=b;i++){
            cin >> fundo[i];
        }

        for (int i=1;i<=n;i++){
            int indDevedor,indCredor,valor;
            cin >> indDevedor >> indCredor >> valor;
            fundo[indDevedor] -= valor;
            fundo[indCredor] += valor;
        }

        int var = 1;
        for (int i=1;i<=b;i++){
            if (fundo[i] < 0){
                var = 0;
            }
        }

        if (var == 1) {
            cout << "S\n";
        } else {
            cout << "N\n";
        }

    }
    return 0;
}
