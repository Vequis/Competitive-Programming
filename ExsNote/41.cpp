#include <iostream>
#include <algorithm>

using namespace std;

int main() {
    int n;
    cin >> n;

    int v[n];
    int qtdInut = 0, qtdCons = 0;

    for (int i=0; i<n; i++){
        cin >> v[i];
    }

    sort(v, v+n);

    for(int i=0; i<n; i++) {
        if (v[i] < 50) {
            qtdInut++;
        } else if (v[i]>=50 and v[i]<85){
            qtdCons++;
        }

    }

    cout << qtdInut << " " << qtdCons << endl;
    return 0;
}
