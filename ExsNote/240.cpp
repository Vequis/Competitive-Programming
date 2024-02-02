#include <iostream>

using namespace std;

int main() {
    int n;
    string pista;
    cin >> n >> pista;
    int paineis = 0;

    for (int i=0;i<n;i++){
        if (pista[i] == 'P' or pista[i] == 'C'){
            paineis += 2;
        } else if (pista[i]=='A'){
            paineis++;
        }
    }

    cout << paineis << endl;

    return 0;
}
