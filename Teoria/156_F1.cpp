#include <iostream>
#include <sstream>

using namespace std;

int posicoes[105][105];
//Linha : Cada GP
//Coluna : Corredor;

void lerPos(int g, int p, int posicoes[105][105]){
    for (int i=0; i<g; i++){

        for (int j=0; j<p; j++){
            cin >> posicoes[i][j];
        }

    }
}

int vSis[105];
int vPont[105]; //Vetor de pontuações dos pilotos para um sistema;
string vWin[10000]; //Vetor que guarda o vencedor para cada sistema;

void pontPilSis(int vPont[], int idPil, int vSis[], int g, int k){
    vPont[idPil] = 0;
    for(int i=0; i<g; i++){
        if (posicoes[i][idPil] <= k){
            vPont[idPil] += vSis[posicoes[i][idPil]-1];
        }
    }
}

void GanhadorSistema(int idSis, int vSis[], int g, int p, int vPont[], int numSis) {
    int k;
    cin >> k;

    int num;
    for (int i=0; i<k; i++){
        cin >> vSis[i];
    }

    for (int i=0; i<p; i++){
        pontPilSis(vPont, i, vSis, g, k);
    }

    int maior = 0;
    string indMaior="";

    for (int i=0; i<p; i++){
        if (vPont[i]>maior){
            maior = vPont[i];
        }
    }


    for (int i=0; i<p; i++){
        if (vPont[i]==maior){
            stringstream temp;

            temp<<(i+1);
            string str;
            temp>>str;
            if(indMaior == ""){
                indMaior += str;
            } else {
                indMaior += " ";
                indMaior += str;
            }
        }
    }


    vWin[idSis+numSis] = indMaior;
}

int main() {
    int g,p;

    cin >> g >> p;

    int numSis = 0;
    int S;

    while (g!=0 and p!=0){
        lerPos(g,p,posicoes);

        cin >> S;

        for(int i=0; i<S; i++){
            GanhadorSistema(i, vSis, g, p, vPont, numSis);
        }

        numSis+=S;

        cin >> g >>p;
    }

    for (int i=0; i<numSis; i++) {
        cout << vWin[i] << endl;
    }

    return 0;
}
