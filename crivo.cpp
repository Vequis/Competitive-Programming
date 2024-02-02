#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

int vetor[10010];
vector<long long int> primos;

void crivo(int limite){

    long long int ind = 2;
    while(ind<=limite){
        if (vetor[ind] == 0) { //elemento == 0 => elemento é primo
            vetor[ind] = 1; //Mostra que o elemento é composto
            long long int var = floor(limite/ind);

            primos.push_back(ind);

            for (int i=ind*ind; i<=var*ind; i+=ind){
                vetor[i] = 1;
            }
        }

        ind++;
    }
}

int main(){

    cout << "Algoritmo para ver se um número é primo." << endl;
    cout << "Digite um número: ";

    long long int n;
    cin >> n;

    crivo(floor(sqrt(n)) + 2);

    bool primo = true;

    for (int i=0; i<primos.size(); i++) {
        if (n%primos[i] == 0){
            cout << "Nao e um numero primo, pois e div por " << primos[i] << endl;
            primo = false;
            break;
        }
    }

    if (primo) cout << "E um numero primo!" << endl;

    return 0;
}