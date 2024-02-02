#include <iostream>
#include <stack>
#include <vector>

using namespace std;

int main(){
    int t;
    stack<char> pilha;
    bool ok = true;
    vector<char> V;

    cin >> t;

    int cont = 0;

    while (cont < t){
        cont++;
        string expressao;
        cin >> expressao;

        ok = true;

        pilha.push('a');

        for (int i=0; i<(int)expressao.size(); i++){

            if (expressao[i]=='(' or expressao[i]=='[' or expressao[i]=='{'){
                pilha.push(expressao[i]);
            } else if (expressao[i]==')' ){
                if (pilha.top() == '(') {
                    if (!pilha.empty()){
                        pilha.pop();
                    }
                } else {
                    ok = false;
                    break;
                }
            } else if (expressao[i]==']' ){
                if (pilha.top() == '[') {
                    if (!pilha.empty()){
                        pilha.pop();
                    }
                } else {
                    ok = false;
                    break;
                }
            } else if (expressao[i]=='}' ){
                if (pilha.top() == '{') {
                    if (!pilha.empty()){
                        pilha.pop();
                    }
                } else {
                    ok = false;
                    break;
                }
            }
        }

        pilha.pop();

        if (!pilha.empty()){
            ok = false;
        }

        if (ok){
            V.push_back('S');
        } else {
            V.push_back('N');
        }

        while(!pilha.empty()){
            pilha.pop();
        }
    }

    for (int i=0; i<t; i++){
        cout << V[i] << endl;
    }
}
