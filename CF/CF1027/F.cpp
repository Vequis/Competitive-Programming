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

// 36 1  6 -> 2
// 

// numero minimo de formas de fazer 
// n multiplicando numeros menores que k

// em x operações, consegue fazer no maximo k^x
// da pra fazer todos os numeros menoers que k^x
// com no max x operacoes????
// se tiver fator primo maior que k: nao
// só tem fatores primos menores que k

// k = 3, 2 operações -> mas nao consegue chegar em 8
// caso
// 1 8 3 

vi primos;
int visitados[1123456];


int memo[1123456];
int k;
// int dp(int n) {
//     if (n <= k) return 1;

//     if (memo[n] != -1) return memo[n];

//     int resp = INF;
//     for (int i = 2; i <=k; i++) {
//         if (n%i == 0) {
//             int cur = dp(n/i);
//             resp = min(resp, cur + 1);
//         }
//     }
//     return memo[n] = resp;
// }

void crivo(int n){
    primos.pb(2);
    visitados[2] = 2;
    for(int i=3; i<=n; i++){
        if (i%2 == 0) {
            visitados[i] = 2;
            continue;
        }
        if(!visitados[i]){
            visitados[i] = i;
            primos.pb(i);
            for(int j=i*i; j<=n; j+=i) visitados[j] = i;
        }
    }
}


void solve() {
    int x, y, k;
    cin >> x >> y >> k;


    int ptr = x;
    while(ptr!=1) {
        cout << visitados[ptr] << endl;
        ptr /= visitados[ptr];
    }
    cout << endl;
}

signed main(){_
    int t;
    cin >> t;
    // t=1;

    crivo(1123450);

    while(t--) {
        solve();
    }

    return 0;
}