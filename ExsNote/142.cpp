#include <iostream>

using namespace std;

int main() {
    int n;
    cin >> n;
    int cedula[n];

    for (int i = 0;i<n;i++) {
        cin >> cedula[i];
    }

    for(int i=0;i<n;i++) {
        int cont = 0;
        if (cedula[i-1]==1) {cont++;}
        if (cedula[i]==1) {cont++;}
        if (cedula[i+1]==1) {cont++;}
        cout << cont << endl;
    }
    return 0;
}
