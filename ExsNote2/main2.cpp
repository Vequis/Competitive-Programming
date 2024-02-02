#include <iostream>
#include <queue>
using namespace std;

int n, m, t;
int matriz[510][510];
int idade[510];
int vetor[510];

bool comanda(int x, int y){
    if (matriz[x][y] == 1) return true;

    for (int i=0; i<n; i++) {
        if (matriz[x][i] == 1){
                if (comanda(i,y)) return true;
        }
    }
}

int P(int x) {
    int idademin = 101;
    //idademin = idade[vetor[x]];
    for (int i=0; i<n; i++){
        if (matriz[i][vetor[x]] == 1) { //Verifica se ele é comandado pela pessoa i
            idademin = min(idademin, P(i));
            idademin = min(idademin, idade[vetor[i]]);
        }
    }
    return idademin;
}

int main(){

    cin >> n >> m >> t;

    int vetorresp[t];
    int cont = 0;

    for (int i=0; i<n; i++) {
        vetor[i] = i;
    }

    queue<int> Q1;
    queue<int> Q2;

    for (int i=0; i<n; i++) {
        cin >> idade[i];
    }

    for (int i=0; i<m; i++){
        int chefe, empregado;
        cin >> chefe >> empregado;

        matriz[chefe-1][empregado] = 1;
    }

    for (int i=0; i<t; i++) {
        char op; cin >> op;

        if (op == 'T'){
            int num1, num2;
            cin >> num1 >> num2;

            int temp = vetor[num1-1];
            vetor[num1-1] = vetor[num2-1];
            vetor[num2-1] = temp;
        }
        else if (op=='P'){
            int num;
            cin >> num;
            if (P(num-1)) vetorresp[cont] = P(num-1);
            else vetorresp[cont] = -1;
            cont++;
        }
    }

    for (int i=0; i<cont; i++) {
        if (vetorresp[i]>0) cout << vetorresp[i] << endl;
        else cout << "*" << endl;
    }

    return 0;
}
