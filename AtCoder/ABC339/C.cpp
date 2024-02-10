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
#define MAXX 1073741823
#define MAX (1<<20)
#define INF 0x3f3f3f3f
#define MODN 1000000007
#define int long long // -> solução divina

using namespace std;

int v[212345];

signed main(){_

    int n;
    cin >> n;

    int soma = 0;
    int minimo = 0;
    for(int i = 1; i<=n; i++) {
        cin >> v[i];
        soma += v[i];
        minimo = min(minimo, soma);
    }

    soma = 0-minimo;

    int resp = INF;
    for(int i = 1; i<=n; i++) {
        soma += v[i];
        resp = min(resp, soma);
    }

    cout << soma << endl;

    return 0;
}
