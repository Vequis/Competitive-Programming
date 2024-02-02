#include <iostream>
#include <stack>

using namespace std;

int main(){

    string expressao;
    stack<char> pilha;
    bool ok;

    cin >> expressao;

    ok = true;
    for (int i=0; i<(int)expressao.size(); i++){
        if (expressao[i]=='('){
            pilha.push('(');
        } else if(expressao[i]==')') {
            if (pilha.empty()) {
                ok = false;
                break;
            } else {
                pilha.pop();
            }
        }
    }

    if (!pilha.empty()) {
        ok = false;
    }

    if (ok){
        cout << "Válida \n";
    } else {
        cout << "Invávelida \n";
    }

    return 0;
}
