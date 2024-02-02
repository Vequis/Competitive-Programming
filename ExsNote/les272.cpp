#include <iostream>
#include <vector>
#include <algorithm>

//Unf

using namespace std;

int numCarta(int num, char naipe){
    int numCarta = (num-1)*4;
    if (naipe=='C') numCarta+=1;
    else if (naipe=='D') numCarta+=2;
    else if (naipe=='H') numCarta+=3;
    else if (naipe=='S') numCarta+=4;

    return numCarta;
}

bool VrfcJogavel(int carta, int cartaAtual) {
    if (carta%4==cartaAtual%4 or carta/4==cartaAtual/4){
        return true;
    } else {
        return false;
    }
}

struct player{
    int id;
    vector<int> cartas;
    int qtdCartas;
};

player jogadores[10];
vector<int> saque;

void AddCarta(int jogadores[],int saque, int i){
    int tam = saque.size();
    jogadores[i].cartas.push_back(saque[0]);
    for (int i=0; i<tam-1; i++){
        saque[i]=saque[i+1];
    }
}

int main() {

    int cartaAtual;
    while (true) {
        int p,m,n;
        cin >> p >> m >>n;
        if (p==0 and m==0 and n==0) break;

        for (int i=0; i<p; i++){
            jogadores[i].cartas.push_back(m);
            jogadores[i].id = i;
            for (int j=0; j<m; j++){
                int num;
                char naipe;
                cin >> num >> naipe;
                jogadores[p].cartas.push_back(numCarta(num, naipe));
            }
        }
        int num;
        char naipe;
        cin >> num >> naipe;
        cartaAtual = numCarta(num, naipe);

        for (int i=p*m+2; i<n; i++){
            int num;
            char naipe;
            cin >> num >> naipe;
            saque[i]=numCarta(num, naipe);
        }

        int sentido;

        for (int i=jogadores[0].qtdCartas-1; i>=0; i--){
            if (VrfcJogavel(jogadores[0].cartas[i],cartaAtual)){
                if (jogadores[0].cartas[i]/4 == 12) sentido *= -1;
                //PAREI POR AQUI ------------------------------------------------------------------------------------------------------------------------------------------

                for (int j=i; j<jogadores[0].qtdCartas; j++){
                    jogadores[0].cartas[j]=jogadores[0].cartas[j+1];
                }
                jogadores[0].cartas.pop_back();
                break;
            }
        }


    }

    return 0;

}
