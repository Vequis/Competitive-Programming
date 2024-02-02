#include <iostream>

using namespace std;

int matriz[1000][1000];

int main(){

    int n, m;
    cin >> n >> m;

    for (int i=0; i<n; i++) {
        for (int j=0; j<m; j++){
            cin >> matriz[i][j];
        }
    }

    int comeco=-1;
    bool escada = true;
    for (int i=0; i<n; i++) {
        for (int j=0; j<m; j++){
            if (matriz[i][j] == 0 and j == m-1) comeco = m-1;
            if (matriz[i][j] == 0) continue;    

            if (j <= comeco) {
                escada = false;
            }

            comeco = j;
            break;
        }
        if (!escada) break;
    }

    if (escada) cout << "S" << endl;
    else cout << "N" << endl;

    return 0;
}