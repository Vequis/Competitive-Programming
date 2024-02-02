#include <iostream>
#include <vector>

using namespace std;

int main() {
    int n;
    cin >> n;

    vector<string> V;

    for (int i=0; i<n; i++) {
        string expressao;
        cin >> expressao;

        bool bA = false;
        bool bJ = false;
        bool bQ = false;
        bool bK = false;

        for (int j=0; j<(int)expressao.size() ; j++) {
            if (expressao[j]=='Q'){
                bQ = true;
            } else if (expressao[j]=='A'){
                bA = true;
            } else if (expressao[j]=='J'){
                bJ = true;
            } else if (expressao[j]=='K'){
                bK = true;
            }
        }

        if (bA and bQ and bJ and bK) {
            V.push_back("Aaah muleke");
        } else {
            V.push_back("Ooo raca viu");
        }
    }

    for (int i =0 ; i<n ; i++) {
        cout << V[i] << endl;
    }

    return 0;
}
