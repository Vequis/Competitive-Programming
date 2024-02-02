#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int n,q;
    cin >> n >> q;

    vector<int> V;

    int v[n];

    for(int i=0; i<n; i++){
        cin >>v[i];
    }

    for (int i=0; i<q; i++) {
        int cont = 0;
        int op;
        cin >> op;

        if (op==1){
            int a;
            int y;
            cin >> a >> y;

            v[a-1] = y;
            sort(v, v+n);
        } else if (op==2) {
            int a, b, x;
            cin >> x >> a >> b;

            for (int j=0; j<n; j++) {
                if (v[j]>a and v[j] < b) {
                    cont++;
                }
            }

            V.push_back(cont);
        }
    }

    for (int i=0; i<(int)V.size(); i++) {
        cout << V[i] << endl;
    }
    return 0;
}
