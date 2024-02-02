#include <iostream>
#include <stack>

using namespace std;

int main(){
    int op;
    int x;
    stack<int> pilha;

    while(cin>>op){
        if (op==0){
            break;
        }

        if (op == 1){
            cin >> x;
            pilha.push(x);
        } else if (op==2){
            if (!pilha.empty()){
                pilha.pop;
            }
        } else if (op == 3){
            if (pilha.empty()){
                cout << "-1\n";
            } else {
                cout << pilha.top() << endl;
            }
        }
    }

    return 0;
}
