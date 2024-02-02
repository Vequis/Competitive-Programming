#include <iostream>
#include <sstream>

using namespace std;

int posicoes[1005][1005];

int vSis[1005];
int vPont[1005]; //Vetor de pontuações dos pilotos para um sistema;
string vWin[10000]; //Vetor que guarda o vencedor para cada sistema;

int main() {
    int g,p;

    cin >> g >> p;

    int numSis = 0;
    int S;

    while (g!=0 and p!=0){

        for (int i=0; i<g; i++){

            for (int j=0; j<p; j++){
                cin >> posicoes[i][j];
            }

        }


        cin >> S;

        for(int i=0; i<S; i++){
            int k;
            cin >> k;

            for (int j=0; j<k; j++){
                cin >> vSis[j];
            }

            for (int j=0; j<p; j++){
                vPont[j] = 0;
                for(int i2=0; i2<g; i2++){
                    if (posicoes[i2][j] <= k){
                        vPont[j] += vSis[posicoes[i2][j]-1];
                    }
                }
            }

            int maior = 0;

            for (int j=0; j<p; j++){
                if (vPont[j]>maior){
                    maior = vPont[j];
                }
            }

            string indMaior="";

            for (int j=0; j<p; j++){
                if (vPont[j]==maior){
                    stringstream temp;

                    temp<<(j+1);
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

            vWin[i+numSis] = indMaior;
        }

        numSis+=S;

        cin >> g >> p;
    }

    for (int i=0; i<numSis; i++) {
        cout << vWin[i] << endl;
    }

    return 0;
}
