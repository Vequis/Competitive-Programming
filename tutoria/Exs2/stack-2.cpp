#include<bits/stdc++.h>

#define _ ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define sz(x) (int)(x).size()
#define pb push_back
#define eb emplace_back
#define vi vector<int>
#define all(x)  (x).begin() , (x).end()
#define fs first
#define sc second
#define ii pair<int, int>
#define vii vector<ii>
#define endl '\n'
#define ll long long int

using namespace std;

stack<int> menores;
int n;
string op;
int num;

int main(){_

    cin >> n;
    
    for (int i=0; i<n; i++){
        cin >> op;
        if (op == "PUSH"){
            cin >> num;
            if (menores.empty()){
                menores.push(num);
            } else {
                int atual = menores.top();
                if (num<atual){
                    menores.push(num);
                } else {
                    menores.push(atual);
                }
            }
        } else if (op == "POP"){
            if (menores.empty()){
                cout << "EMPTY" << endl;
            } else {
                menores.pop();
            }
        } else { //if op == "MIN"
            if (menores.empty()){
                cout << "EMPTY" << endl;
            } else {
                cout << menores.top() << endl;
            }
        }
    }

    return 0;
}