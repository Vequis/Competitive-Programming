#include <iostream>
#include <string>

using namespace std;

void imprime (string l[], int tamanho){
    for (int indice = tamanho - 1; indice>=0; indice--){
        cout << l[indice] << endl;
    }
}

int main() {
    string letras[] = {"a", "z", "e", "f", "c", "r", "w", "s", "b", "d",};

    imprime(letras, 3);

    cout << endl;

    imprime(letras, 2);

    return 0;
}