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

stack<char> operadores;
int n;
string st;

int main(){_

    cin >> n;

    for (int i=0; i<n; i++){
        cin >> st;

        for (int j=0; j<sz(st); j++){
            if (st[j] == '(' or st[j] == ')'){
                continue;
            } else if ( (st[j] >='a' and st[j] <= 'z') or (st[j]>='A' and st[j] <= 'Z' ) or (st[j]>='0' and st[j]<='9')){
                cout << st[j];
                while(!operadores.empty()){
                    cout << operadores.top();
                    operadores.pop();
                }
            } else {
                operadores.push(st[j]);
            }
        }

        while(!operadores.empty()){
            cout << operadores.top();
            operadores.pop();
        }

        cout << endl;
    }

    return 0;
}