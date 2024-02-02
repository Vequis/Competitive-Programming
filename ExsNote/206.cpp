#include <iostream>

using namespace std;

int main() {
    int posKung,posLu;

    for (int i=0;i<16;i++){
        int leitura;
        cin >> leitura; //Lendo a posição ddo lutador i;
        if (leitura == 1) posKung = i;
        else if (leitura == 9) posLu = i;
    }

    if( (posKung/2) == (posLu/2) ){
        cout << "oitavas" << endl;
    } else if( (posKung/4) == (posLu/4) ) {
        cout << "quartas" << endl;
    } else if( (posKung/8) == (posLu/8) ) {
        cout << "semifinal" << endl;
    } else if( (posKung/16) == (posLu/16) ) {
        cout << "final" << endl;
    }

    return 0;
}
