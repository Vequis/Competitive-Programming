#include <iostream>

using namespace std;

int main() {
    int n;
    cin >> n;
    int quadrado[n+1];

    //Lendo os valores.
    for (int i=1;i<=n;i++) {
        cin >> quadrado[i];
    }

    //Vendo qual cor para o quadrado específico
    for (int i=1;i<=n;i++){ //Para cada quadrado
        if(quadrado[i]== -1) { //Verificação se está pintado ou nao
            for(int j=1;j<=n;j++){ //For para a distancia
                if (((quadrado[i+j] == 0) and (i+j<=n)) or ((quadrado[i-j] == 0) and (i-j>0))) { //Verificação se a uma distancia j esta um tom 0
                    if(j<=9){quadrado[i]=j;}
                    if(j>9){quadrado[i]=9;}
                    break;
                }
            }
        }
    }

    for (int i=1;i<=n;i++){
        cout << quadrado[i] << " ";
    }
    cout << endl;
    return 0;
}
