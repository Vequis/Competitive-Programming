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

vi ngr; //indice
vii cidades;
int n, x, p;
stack<int> pilha;

int main(){_
    cin >> n;

    cidades = vii(n+1);
    ngr = vi(n+1, -2);

    cidades.pop_back();

    for (int i=0; i<n; i++){
        cin >> x >> p;
        cidades[i] = {x,p};
    }

    sort(all(cidades));

    for (int i=0; i<n; i++){
        if (!pilha.empty()) cout << cidades[i].sc << ' ' << cidades[pilha.top()].sc << endl;

        while(!pilha.empty() and cidades[i].sc > cidades[pilha.top()].sc){
            ngr[pilha.top()] = i;
            pilha.pop();
        }

        pilha.push(i);
    }

    while(!pilha.empty())pilha.pop();

    // for (int i=0; i<n; i++){
    //     cout << ' ' << ngr[i]+1;
    // }
    // cout << endl;

    for (int i=n-1; i>=0; i--){
        while(!pilha.empty() and cidades[i].sc > cidades[pilha.top()].sc){
            if (ngr[i] == -2){
                ngr[i] = i;
                continue;
            }

            if (cidades[ngr[pilha.top()]].fs - cidades[pilha.top()].fs > cidades[pilha.top()].fs - cidades[i].fs){
                // ngr[pilha.top()] = ; não muda 
            } else if (cidades[ngr[pilha.top()]].fs - cidades[pilha.top()].fs < cidades[pilha.top()].fs - cidades[i].fs){
                ngr[pilha.top()] = i;
            } else {
                if (cidades[ngr[pilha.top()]].sc >= cidades[i].sc) ngr[pilha.top()] = ngr[pilha.top()];
                else ngr[pilha.top()] = i; 
            }

            pilha.pop();
        }

        pilha.push(i);
    }

    cout << ngr[0] + 1;

    for (int i=1; i<n; i++){
        cout << ' ' << ngr[i]+1;
    }

    cout << endl;

    return 0;
}