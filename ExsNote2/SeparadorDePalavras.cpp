#include <iostream>
#include <string.h>
#include <stdio.h>

using namespace std;


int main(){

    int cont = 0;

    string vetor[100];
    string s;

    getline(cin,s);

    int contC=0;

    for (int i = 0; i<(int)s.size(); i++){

        if (s[i] != ' '){
            vetor[cont][contC] = s[i];
            contC++;
        } else {
            cont++;
            contC = 0;
        }
    }

    cout << vetor[0] << endl;

    for (int i =0; i<=cont; i++){
        cout << "vetor " << i << " : ";
        cout << vetor[i] << endl;

    }

    return 0;

}
