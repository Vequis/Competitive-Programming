#include <iostream>

using namespace std;

char matriz[110][110];

int main(){

    int n;
    cin >> n;

    for (int i=0; i<n; i++) {
        for (int j=0; j<n; j++){
            char c;
            cin >> c;
            matriz[i][j] = c;
        }
    }

    int sentido = 1; // 1 Quando é da direita para a esquerda:
    int cont = 0;
    int maximo = 0;
    for (int i=0; i<n; i++){

        if (sentido == 1){
            for (int j=0; j<n; j++){
                if (matriz[i][j] == 'o'){
                    cont++;
                    if (cont>maximo) maximo = cont;
                } else if (matriz[i][j] == 'A'){
                    cont=0;
                }
            }
        } else {
            for (int j=n-1; j>=0; j--){
                if (matriz[i][j] == 'o'){
                    cont++;
                    if (cont>maximo) maximo = cont;
                } else if (matriz[i][j] == 'A'){
                    cont=0;
                }
            }
        }
        sentido^=1;
    }

    cout << maximo << endl;
    return 0;
}