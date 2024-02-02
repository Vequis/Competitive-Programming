#include <iostream>

using namespace std;

int main() {
    int n,k,soma,somaP;
    cin >> n;
    int a[n];

    soma = 0;
    for (int i=0;i<n;i++){
        cin >> a[i];
        soma += a[i];
    }

    somaP = 0;
    for (int i=0;i<n;i++){
        somaP+=a[i];
        if(somaP==(soma/2)){
            cout << i+1 << endl;
            break;
        }
    }
    return 0;
}

