#include <iostream>
#include <algorithm>

using namespace std;

struct piloto{
    int id;
    int posicoes[101];
    int pontuacao[11] = {0,0,0,0,0,0,0,0,0,0,0};
};

int ordem(piloto a, piloto b,int z){
    a.pontuacao[z]>b.pontuacao[z];
}

int main() {
    int g,p;
    int s,k;
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
            sort(pilotos, pilotos + p, s, ordem);

            for (int j=0; j<p)
        }

        for (int i=0; i<s; i++){
            for (int j=0; j<p; j++){
                if (pilotos[j].pontuacao[i] != pilotos[j+1].pontuacao[i]){
                    for (k=0; k<j; k++){
                        cout << pilotos[k].id << " ";
                    }
                    break;
                }
                cout << endl;
            }

        //Zerar pontuacoes
        for (int i=0; i<101; i++){
            for (int j=0;j<11; j++) {
                pilotos[i].pontuacao[j] = 0;
            }
        }

        }
    }
}
