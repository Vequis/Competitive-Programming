#include <iostream>

using namespace std;

int main() {
    int m,n;
    cin >> m >> n;
    int maxi = max(m,n);

    int X[maxi],Y[maxi];

    for (int i=0; i<maxi; i++) {
        if (i<m){
            cin >> X[i];
        } else {
            X[i] = 0;
        }
    }


    for (int i=0; i<maxi; i++) {
        if (i<n){
            cin >> Y[i];
        } else {
            Y[i] = 0;
        }
    }

    int R[maxi];
    int sobra=0;
    int cont = 0;
    for (int i=maxi-1;i>=0;i--) {
        R[i] = X[i] + Y[i] + sobra;
        if (R[i] >=2){
            sobra = 1;
            R[i]-=2;
        } else if (R[i]<2){
            sobra=0;
        }

        if (R[i] == 1 and cont == 0){
            cont = i;
        }
    }

    for (int i = 0; i<=cont; i++){
        cout << R[i] << " ";
    }
    cout << endl;
    return 0;
}
