#include <iostream>

using namespace std;

int main() {

    int m[6][6];

    for (int i=0; i<6; i++) {
        for (int j=0; j<6; j++){
            cin >> m[i][j];
        }
    }

    int somaTemp = 0;
    int maiorSoma = -10000;

    for (int i=1; i<5; i++) {
        for (int j=1; j<5; j++){
            somaTemp = m[i-1][j-1] + m[i-1][j] + m[i-1][j+1] + m[i][j] + m[i+1][j-1] + m[i+1][j] + m[i+1][j+1];
            if (somaTemp > maiorSoma) maiorSoma = somaTemp;
        }
    }

    cout << maiorSoma << endl;
    return 0;
}
