#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

int vetor[100100];
vector<int> primos;

void crivo(int n) {
    for (int i=2; i<=n; i++){
        if (vetor[i] == 0){
            primos.push_back(i);
            int limite = floor(n/i);
            for (int j=i*i; j<=limite*i; j+=i) vetor[j] = 1;
        }
    }
}

int main() {
    int n;
    cin>> n;

    crivo(n);

    for (int i=0; i<primos.size(); i++) cout << primos[i] << endl;
    return 0; 
}