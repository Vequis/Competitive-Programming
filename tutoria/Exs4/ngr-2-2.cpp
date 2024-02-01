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

stack<int> pilha;
vi ngrr, ngrl;
int n, x, p, dist1, dist2;
vii cidades;
map <int, int> id;

int main(){_

    cin >> n;

    cidades = vii(n+1);
    ngrr = vi(n+1, 0);
    ngrl = vi(n+1, 0);

    for (int i=1; i<=n; i++){
        cin >> x >> p;

        cidades[i] = {x,p};
        id[x] = i;
    }

    sort(1+all(cidades));

    // for (int i=1; i<=n; i++) cout << cidades[i].fs  << ' ' << cidades[i].sc << ' ' << id[cidades[i].fs] << ' ' << endl;

    for (int i=1; i<=n; i++){
        while(!pilha.empty() and cidades[i].sc > cidades[pilha.top()].sc){
            ngrr[pilha.top()] = i;
            pilha.pop();
        }

        pilha.push(i);
    }

    while(!pilha.empty()) pilha.pop();

    for (int i=n; i>=1; i--){
        while(!pilha.empty() and cidades[i].sc > cidades[pilha.top()].sc){
            ngrl[pilha.top()] = i;
            pilha.pop();
        }

        pilha.push(i);
    }

    vi resposta(n+1);

    for (int i=1; i<=n; i++){
        if (ngrr[i] == 0 and ngrl[i] == 0) {
            resposta[id[cidades[i].fs]] = -1;
            continue;
        }
        
        if (ngrr[i] != 0) dist1 = cidades[ngrr[i]].fs - cidades[i].fs;
        else dist1 = INT_MAX;

        if (ngrl[i] != 0) dist2 = cidades[i].fs - cidades[ngrl[i]].fs ;
        else dist2 = INT_MAX;

        if (dist1 == dist2) {
            if (cidades[ngrr[i]].sc > cidades[ngrl[i]].sc) resposta[id[cidades[i].fs]] = id[cidades[ngrr[i]].fs];
            else resposta[id[cidades[i].fs]] = id[cidades[ngrl[i]].fs];
        }
        else if (dist1<dist2) resposta[id[cidades[i].fs]] = id[cidades[ngrr[i]].fs];
        else resposta[id[cidades[i].fs]] = id[cidades[ngrl[i]].fs];            
    }

    for (int i=1; i<=n; i++){
        if (i!=1) cout << ' ';

        cout << resposta[i];
    }

    cout << endl;

    return 0;
}