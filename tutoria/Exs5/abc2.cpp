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

ll MAXN = 10e9 + 7;

string st;

int aux, tam, soma;

int main(){_
    cin >> st;

    tam = sz(st);

    for (int i=tam-1; i>=0; i--){
        soma = ( soma + ((int)st[i] - 'A' + 1) * aux)%MAXN;

        aux = (aux*26)%MAXN;
    }

    cout << soma << endl;

    return 0;
}