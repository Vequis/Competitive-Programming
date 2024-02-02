#include <iostream>

using namespace std;

bool par(int n) {
    if (n%2==0) return true;
    else return false;
}

int main() {

    int t;
    cin >> t;

    for (int i=0; i<t; i++) {

        int soma = 0;

        int n, k;
        cin >> n >> k;

        if ( par(k) and !par(n)) {
            cout << "NO" << endl;
            continue;
        }

        if (par(n)) {
            if (par(k)){
                soma+=k-1;
                if (soma+1>n){
                    cout << "NO" << endl;
                    continue;
                } else {
                    cout << "YES" << endl;
                    for (int i=0; i<k-1; i++) {
                        cout << "1 ";
                    }

                    cout << n-soma << endl;
                }

            } else {
                soma+=2*(k-1);
                if (soma+2 > n){
                    cout << "NO" << endl;
                    continue;
                } else {
                    cout << "YES" << endl;
                    for (int i=0; i<k-1; i++){
                        cout << "2 ";
                    }

                    cout << n-soma << endl;
                }
            }

        } else {
            soma+= k-1;
            if (soma+1>n){
                cout << "NO" << endl;
                continue;
            } else {
                cout << "YES" << endl;
                for (int i=0; i<k-1; i++) {
                    cout << "1 ";
                }

                cout << n-soma << endl;
            }
        }
    }

    return 0;
}
