#include <iostream>

using namespace std;

int main() {
    int n;
    cin >> n;

    int v[n];

    for (int i=0; i<n; i++) {
        cin >> v[i];
    }

    int pm=v[0];
    int pb=v[n-1];

    int resp = 0;

    int contB = 1;
    int contA = n-2;

    while (true) {
        if (pm==pb){
            resp = pm;
            pb+=v[contA];
            pm+=v[contB];
            contA--;
            contB++;
        } else if (pm>pb) {
            pb+=v[contA];
            contA--;
        } else {
            pm+=v[contB];
            contB++;
        }

        if (contB-1>=contA+1){
            break;
        }
    }

    cout << resp << endl; return 0;
}
