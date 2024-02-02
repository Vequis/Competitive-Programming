#include <iostream>
#include <vector>
#include <stack>

using namespace std;
stack<char> pilha;

int main() {

    int n;
    cin >> n;

    vector<string> V;

    for (int i=0; i<n; i++) {

        string expressao;
        cin >> expressao;

        bool ok = true;

        pilha.push('p');

        for (int j=0; j<(int)expressao.size() ; j++) {
            if (expressao[j]=='Q'){
                ok = true;
                pilha.push('Q');
            } else if (expressao[j]=='J'){
                if (pilha.top()!= 'Q') ok = false;
                pilha.push('J');
            } else if (expressao[j]=='K'){
                if (pilha.top()!= 'J') ok = false;
                pilha.push('K');
            } else if (expressao[j]=='A'){
                if (pilha.top()!= 'K') ok = false;
                pilha.push('A');
            }
        }

        if (ok) {
            V.push_back("Agora vai");
        } else {
            V.push_back("Agora apertou sem abracar");
        }


    }

    for (int i=0; i<n; i++) {
        cout << V[i] << endl;
    }

    return 0;
}
