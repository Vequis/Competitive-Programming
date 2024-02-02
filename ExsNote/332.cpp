#include <iostream>

using namespace std;

int main() {
    int n,saldo;
    cin >> n >> saldo;

    int menor = saldo;
    int num;
    for(int i=0; i<n; i++){
        cin >> num;
        saldo += num;
        if(saldo < menor) menor = saldo;
    }

    cout << menor << endl;
    return 0;
}
