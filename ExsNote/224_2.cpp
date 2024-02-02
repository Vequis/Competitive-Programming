#include <iostream>

using namespace std;

int main() {
    int n;
    cin >> n;
    int v[n];

    cin >> v[0];
    int menor = v[0];

    for (int i=1; i<n; i++) {
        cin >> v[i];

        if (v[i] < menor){
            menor = v[i];
        }
    }

    cout << menor << endl;
    return 0;
}
