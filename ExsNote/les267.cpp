#include <iostream>
#include <stack>
#include <string>

using namespace std;

int main() {
    int n;
    cin >> n;
    n++;

    bool ok = true;

    stack<char> pilha;

    while(n--){
        string exp;
        getline(cin, exp);

        for (int i=0; i<(int)exp.size(); i++) {
            if (exp[i] == '{'){
                pilha.push(exp[i]);
            } else if (exp[i] == '}'){
                if (pilha.empty()){
                    ok = false;
                    break;
                } else {
                    pilha.pop();
                }
            }
        }

    }

    if (!pilha.empty()) {
        ok = false;
    }

    if (ok) {
        cout << "S" << endl;
    } else {
        cout << "N" << endl;
    }

    return 0;
}
