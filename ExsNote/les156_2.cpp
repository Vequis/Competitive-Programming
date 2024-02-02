#include <iostream>
#include <algorithm>

using namespace std;

struct piloto{
    int id;
    int posicoes[101];
    int pontuacao[11] = {0,0,0,0,0,0,0,0,0,0,0};
};

int main() {
    int g,p;
    int s,k;
    int ordenado = 0;
    piloto pilotos[101];

    while (true){
        cin >> g >> p;
        if (g==0 and p == 0) break;

        for (int i=0; i<g; i++){
            for (int j=0; j<p; j++){
                cin >> pilotos[j].posicoes[i];
            }
        }

        for (int i=0; i<p; i++){
            pilotos[i].id = i+1;
        }

        cin >> s;
        for (int i=0; i<s; i++){
            cin >> k;
            int matriz[s][k];
            for (int j=0; j<k; j++){
                cin >> matriz[i][j];
                for (int k=0;k<p;k++){
                    for (int l=0; l<g;l++){
                        if (pilotos[k].posicoes[l]==j){
                            pilotos[k].pontuacao[s] += j*matriz[i][j];
                        }
                    }
                }
            }
            //Bubble
            while (ordenado==0){
                ordenado = 1;
                for (int k=0; k<(p-1); k++){
                    if (pilotos[k].pontuacao[i] > pilotos[k+1].pontuacao[i]){
                        int temp;
                        temp = pilotos[k].pontuacao[i];
                        pilotos[k].pontuacao[i] = pilotos[k+1].pontuacao[i];
                        pilotos[k+1].pontuacao[i] = temp;
                        ordenado = 0;
                    }
                }
            }
        }

        for (int i=0; i<s; i++){
            for (int j=0; j<p; j++){
                cout << "a" << endl;
                if (pilotos[j].pontuacao[i] != pilotos[j+1].pontuacao[i]){
                    for (k=0; k<j; k++){
                        cout << "AAAAAAAAAAAa";
                        cout << pilotos[k].id << " ";
                    }
                    break;
                }
                cout << endl;
            }

        }
            //Zerar pontuacoes
        for (int i=0; i<101; i++){
            for (int j=0;j<11; j++) {
                pilotos[i].pontuacao[j] = 0;
            }
        }

    }
}
