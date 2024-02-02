#include <iostream>

using namespace std;

int main(){

    int vetor[10];

    int n; cin >> n;

    for (int i=0; i<n; i++) cin >> vetor[i];

    int x = 0;
    for (int i=0; i<n; i++){
        cout <<  x << endl;
        cout << x << " XOR " <<  vetor[i] << " = ";
        x^=vetor[i];
        cout << x << endl;
    }

    return 0;
}
