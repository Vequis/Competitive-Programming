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

queue<int> fila;
queue<int>::iterator it;
int n, x, y;
string cmd;

int main(){_

    while (cin >> cmd){
        if (cmd == "i"){
            cin >> x;
            fila.push(x);
        } else if (cmd == "f"){
            if (!fila.empty()){
                cout << fila.front(); endl;
            }
        } else if (cmd == "p"){
            if (!fila.empty()){
                fila.pop();
                cout << "retirou" << endl;
            }
        }
    }

    //Não da pra iterar
    return 0;
}