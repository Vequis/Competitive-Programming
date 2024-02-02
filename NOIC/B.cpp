#include <iostream>

using namespace std;

int main(){

    int vetor[100100];

    int n;
    cin >> n;

    int ant;
    cin >> ant;

    int contM = 1;
    int cont = 1;
    for (int i=1; i<n; i++){

        int num;
        cin >> num;

        if (num>ant){
            cont++;
        } else {
            if (cont > contM) contM = cont;
            cont = 1;
        }

        ant = num;
    }
    if (cont > contM) contM = cont;

    cout << contM << endl;
    return 0;
}