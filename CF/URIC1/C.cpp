#include <iostream>
#include <vector>

using namespace std;

int main() {
    int n;
    cin >> n;

    vector<int> V;

    for (int i=0; i<n; i++) {

        int n7 = 0;
        int nQ = 0;
        int nJ = 0;
        int nK = 0;
        int nA = 0;

        string expressao;
        cin >> expressao;

        int tiradas = 0;

        for (int j=0; j<(int)expressao.size(); j++) {

            if (expressao[j]=='7'){
                n7++;
            } else if (expressao[j]=='Q') {
                if (n7>0) {
                    n7--;
                    nQ++;
                } else { tiradas++;}
            } else if (expressao[j]=='J') {
                if (nQ>0) {
                    nQ--;
                    nJ++;
                } else { tiradas++;}
            } else if (expressao[j]=='K') {
                if (nJ>0) {
                    nJ--;
                    nK++;
                } else { tiradas++;}
            } else if (expressao[j]=='A') {
                if (nK>0) {
                    nK--;
                    nA++;
                } else { tiradas++;}
            } else {
                tiradas++;
            }

        }
        tiradas+=n7 + 2*nQ + 3*nJ + 4*nK;

        V.push_back(tiradas);
    }

    for (int i=0; i<n; i++) {
        cout << V[i] << endl;
    }
}
