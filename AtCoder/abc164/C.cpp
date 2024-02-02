#include <iostream>
#include <algorithm>

using namespace std;

int main(){

    int n;
    cin >> n;

    string v[n];

    for (int i=0;i<n; i++) {
        cin >> v[i];
    }

    sort(v, v+n);

    int cont = 1;

    for (int i=1; i<n; i++){
        if (v[i] != v[i-1]) {
            cont++;
        }
    }

    cout << cont << endl;
    return 0;
}
