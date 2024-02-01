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

int w[111];
int v[111];

int memo[111][112345];

int dp(int n, int valor) {
    if (valor < 0) return INF;
    if (valor == 0) return 0;
    if (n == 0) return INF;

    if (memo[n][valor] != -1) return memo[n][valor];

    return memo[n][valor] = min(dp(n-1, valor), dp(n-1, valor - v[n]) + w[n]);
}

signed main(){_

    int n;
    cin >> n;

    int we;
    cin >> we;

    memset(memo, -1, sizeof(memo));

    for(int i = 1; i <=n; i++) cin >> w[i] >> v[i];

    int soma = 0;
    for(int i = 1; i <= n; i++) soma += v[i];

    for(int i = soma; i >= 0; i--) {
        if (dp(n, i) <= we) {
            cout << i << endl;
            return 0;
        }
    } 

    return 0;
}
